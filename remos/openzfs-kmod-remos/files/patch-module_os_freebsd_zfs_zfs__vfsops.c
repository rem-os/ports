--- module/os/freebsd/zfs/zfs_vfsops.c.orig	2020-08-27 04:20:54 UTC
+++ module/os/freebsd/zfs/zfs_vfsops.c
@@ -1724,9 +1724,6 @@ zfsvfs_teardown(zfsvfs_t *zfsvfs, boolean_t unmounting
 		 * v_vfsp set to the parent's filesystem's vfsp.  Note,
 		 * 'z_parent' is self referential for non-snapshots.
 		 */
-#ifdef FREEBSD_NAMECACHE
-		cache_purgevfs(zfsvfs->z_parent->z_vfs, true);
-#endif
 	}
 
 	/*
