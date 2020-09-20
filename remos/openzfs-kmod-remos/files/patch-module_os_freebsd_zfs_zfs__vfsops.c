--- module/os/freebsd/zfs/zfs_vfsops.c.orig	2020-09-18 19:13:47 UTC
+++ module/os/freebsd/zfs/zfs_vfsops.c
@@ -906,9 +906,7 @@ zfsvfs_init(zfsvfs_t *zfsvfs, objset_t *os)
 	 * are looking for the exact name (which is always the case on
 	 * FreeBSD).
 	 */
-	zfsvfs->z_use_namecache = !zfsvfs->z_norm ||
-	    ((zfsvfs->z_case == ZFS_CASE_MIXED) &&
-	    !(zfsvfs->z_norm & ~U8_TEXTPREP_TOUPPER));
+	zfsvfs->z_use_namecache = B_FALSE;
 
 	return (0);
 }
@@ -1531,9 +1529,6 @@ zfsvfs_teardown(zfsvfs_t *zfsvfs, boolean_t unmounting
 		 * v_vfsp set to the parent's filesystem's vfsp.  Note,
 		 * 'z_parent' is self referential for non-snapshots.
 		 */
-#ifdef FREEBSD_NAMECACHE
-		cache_purgevfs(zfsvfs->z_parent->z_vfs, true);
-#endif
 	}
 
 	/*
