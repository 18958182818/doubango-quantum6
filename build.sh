BUILD_LIBS=${HOME}/telecom/build_libs

export PATH=${BUILD_LIBS}/bin:${PATH}
export LD_LIBRARY_PATH=${BUILD_LIBS}/lib:${LD_LIBRARY_PATH}
 
if [ -f autogen.sh ]; then
    ./autogen.sh
fi

cd bindings
if [ -f autogen.sh ]; then
    ./autogen.sh
fi
cd ..

#　关键一步，必须！
# autoreconf -fiv
 
rm config.log

./configure  \
    --prefix=${BUILD_LIBS}  \
    CFLAGS=-I${BUILD_LIBS}/include \
    LDFLAGS=-L${BUILD_LIBS}/lib \
    LIBS="-lm -lc -lswresample -lavutil -lyuv -ljpeg " \
    --with-ssl --with-srtp --with-vpx --with-yuv --with-amr --with-speex --with-speexdsp --enable-speexresampler --enable-speexdenoiser --with-opus --with-gsm --with-ilbc --with-g729 --with-ffmpeg
 
# --with-g729
#    --with-speexdsp --with-ffmpeg --with-opus
 
make
 
make install
