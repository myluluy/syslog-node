cmd_Release/syslog.node := /usr/bin/clang++ -bundle -undefined dynamic_lookup -Wl,-no_pie -Wl,-search_paths_first -mmacosx-version-min=10.7 -arch x86_64 -L./Release -stdlib=libc++  -o Release/syslog.node Release/obj.target/syslog/src/main.o 
