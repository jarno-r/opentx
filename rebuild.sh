if ! [ "$1" == '--noclean' ]; then
    rm -rf build-stuff
fi
mkdir build-stuff
cd build-stuff
cmake -DDISABLE_COMPANION=ON -DSIMU_TARGET=OFF -DPCB=9XRPRO -DDEFAULT_MODE=2 -DGVARS=YES -DPPM_UNIT=US -DHELI=NO -DLUA=NO -DCMAKE_BUILD_TYPE=Release ../
make -j`nproc` firmware
