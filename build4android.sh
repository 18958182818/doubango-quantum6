if [ "$1" == "all" ]; then
    rm -rf android-projects/output/gpl

     ./autogen.sh

    cd bindings
    ./autogen.sh
    cd ..
fi

./android_build.sh $1

