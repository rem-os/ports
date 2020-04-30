--- libpkg/private/pkg.h.orig	2020-04-30 17:31:15 UTC
+++ libpkg/private/pkg.h
@@ -445,6 +445,7 @@ struct pkg_option {
 struct http_mirror {
 	struct url *url;
 	struct http_mirror *next;
+	bool reldoc;
 };
 
 struct pkg_repo_meta_key {
