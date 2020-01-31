#!/bin/sh

# Build Manifest
BM=${1}

# Where to create repo
STAGEDIR="${2}"

REPONAME="RemOS"
if [ "$(jq -r '."pkg-repo-name" | length' ${BM})" != "0" ]; then
	REPONAME=`jq -r '."pkg-repo-name"' ${BM}`
fi
TRAINNAME="RemOS"
if [ "$(jq -r '."pkg-train-name" | length' ${BM})" != "0" ]; then
	TRAINNAME=`jq -r '."pkg-train-name"' ${BM}`
fi
# Do the first-time setup of package repo
if [ ! -e "${STAGEDIR}/etc/pkg/Train.conf" ] ; then

	# Disable the FreeBSD repo by default
	if [ -e "${STAGEDIR}/etc/pkg/FreeBSD.conf" ] ; then
		mkdir -p ${STAGEDIR}/usr/local/etc/pkg/repos || true
		echo "FreeBSD: { enabled: no }" >${STAGEDIR}/usr/local/etc/pkg/repos/FreeBSD.conf
	fi

	# Do Setup for pkg repo
	BM_PUBKEY="none"
	if [ "$(jq -r '."pkg-repo"."pubKey" | length' ${BM})" != "0" ]; then
		echo "Saving pkg ports repository public key"
		jq -r '."pkg-repo"."pubKey" | join("\n")' ${BM} \
		> ${STAGEDIR}/usr/share/keys/pkg/${REPONAME}.pub
		BM_PUBKEY="/usr/share/keys/pkg/${REPONAME}.pub"
		if [ "$(jq -r '."pkg-repo"."url" | length' ${BM})" != "0" ]; then
			BM_PKGURL="$(jq -r '."pkg-repo"."url"' ${BM})"
			cat >${STAGEDIR}/etc/pkg/Train.conf <<-EOF
			${REPONAME}: {
			  url: "${BM_PKGURL}",
			  signature_type: "pubkey",
			  pubkey: "${BM_PUBKEY}",
			}
			EOF
		fi
	else
		if [ "$(jq -r '."pkg-repo"."url" | length' ${BM})" != "0" ]; then
			BM_PKGURL="$(jq -r '."pkg-repo"."url"' ${BM})"
			cat >${STAGEDIR}/etc/pkg/Train.conf <<-EOF
			${REPONAME}: {
			  url: "${BM_PKGURL}",
			  signature_type: "none",
			}
			EOF
		fi
	fi
fi
