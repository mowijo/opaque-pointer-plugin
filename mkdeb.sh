  


WD=/tmp/mkdeb
USR_SHARE_DOCS=$WD"/usr/share/doc/qtcreator-plugin-wizard-opaque-class"
CHANGE_LOG_FILE=$WD"/usr/share/doc/qtcreator-plugin-wizard-opaque-class/changelog.Debian.gz"
rm -rf $WD
mkdir -p $WD/usr/share/qtcreator/templates/wizards/opaque-class
mkdir -p $USR_SHARE_DOCS
cp src/* $WD/usr/share/qtcreator/templates/wizards/opaque-class/
cp -rf DEBIAN $WD
cp copyright.txt $USR_SHARE_DOCS/copyright
find $WD -type d | xargs chmod 755 
#gzip -c changelog.txt > $CHANGE_LOG_FILE
gzip --best -c changelog.txt > changelog.Debian.gz
mv changelog.Debian.gz $USR_SHARE_DOCS
chmod 0644 $USR_SHARE_DOCS/*
fakeroot dpkg-deb --build $WD

VERSION=`cat DEBIAN/control | grep Version | awk '{print $2}'`
PACKAGENAME=`cat DEBIAN/control | grep Package | awk '{print $2}'`
ARCH=`cat DEBIAN/control | grep Architecture | awk '{print $2}'`
FILENAME=$PACKAGENAME"_"$VERSION"_"$ARCH".deb"
mv $WD/../mkdeb.deb $FILENAME
