--- libpkg/packing.c.orig	2020-02-11 08:21:19 UTC
+++ libpkg/packing.c
@@ -316,14 +316,14 @@ packing_set_format(struct archive *a, pkg_formats form
 
 	switch (format) {
 	case TZS:
-#ifdef HAVE_ARCHIVE_WRITE_ADD_FILTER_ZSTD
+/* #ifdef HAVE_ARCHIVE_WRITE_ADD_FILTER_ZSTD */
 		if (archive_write_add_filter_zstd(a) == ARCHIVE_OK) {
-			if (archive_write_set_filter_option(a, NULL, "compression-level", "20") != ARCHIVE_OK) {
+			if (archive_write_set_filter_option(a, NULL, "compression-level", "8") != ARCHIVE_OK) {
 				pkg_emit_error("bad compression-level");
 			}
 			return ("tzst");
 		}
-#endif
+/* #endif */
 		pkg_emit_error(notsupp_fmt, "zstd", "xz");
 		/* FALLTHRU */
 	case TXZ:
