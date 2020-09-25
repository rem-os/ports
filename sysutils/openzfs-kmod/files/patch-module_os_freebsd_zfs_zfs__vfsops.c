--- module/os/freebsd/zfs/zfs_vfsops.c.orig	2020-09-18 19:13:47 UTC
+++ module/os/freebsd/zfs/zfs_vfsops.c
@@ -1532,7 +1532,7 @@ zfsvfs_teardown(zfsvfs_t *zfsvfs, boolean_t unmounting
 		 * 'z_parent' is self referential for non-snapshots.
 		 */
 #ifdef FREEBSD_NAMECACHE
-		cache_purgevfs(zfsvfs->z_parent->z_vfs, true);
+		cache_purgevfs(zfsvfs->z_parent->z_vfs);
 #endif
 	}
 
