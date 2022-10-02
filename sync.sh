rsync -e "ssh -p 22" -av /mnt/c/Git/libcurl-cpp-master/ --exclude .git/ --exclude build/ --exclude sync.sh --delete ysbaek@ysbaekFox.iptime.org:/home/ysbaek/ysbaek/libcurl-cpp-master
