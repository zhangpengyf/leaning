echo "install software"
sudo apt install zsh emacs openssh-server build-essential bison flex libgmp3-dev libmpc-dev libmpfr-dev texinfo libisl-dev xorriso grub2 qemu qemu-system-x86 -y

# 也可以直接在浏览器下载
rm -rf binutils-2.30
rm -rf gcc-7.3.0
#wget 'https://ftp.gnu.org/gnu/binutils/binutils-2.30.tar.xz'
#wget 'https://ftp.gnu.org/gnu/gcc/gcc-7.3.0/gcc-7.3.0.tar.xz'
tar -xvJf binutils-2.30.tar.xz
tar -xvJf gcc-7.3.0.tar.xz

echo "instal gcc prerequisites"
cd gcc-7.3.0
# 该命令会从国外网站下载相关依赖，若无法下载请自行解决网络问题
./contrib/download_prerequisites
cd ..

echo "install dir $HOME/opt/cross" 
export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

mkdir $HOME/src

echo "build binutils"
cd $HOME/src 
mkdir build-binutils
cd build-binutils
../binutils-x.y.z/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install

cd $HOME/src
 
# The $PREFIX/bin dir _must_ be in the PATH. We did that above.
which -- $TARGET-as || echo $TARGET-as is not in the PATH

echo "build-gcc"
mkdir build-gcc
cd build-gcc
../gcc-x.y.z/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc

$HOME/opt/cross/bin/$TARGET-gcc --version

echo "install ok"
