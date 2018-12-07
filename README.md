# The Curie experiment

Curie is a native lisp dialect geared towards scientific computing. Named after Marie Curie, yes, and also with a pun, yes. It is first an experiment on learning how to design and implement a LISP compiler. If this project lives long enough, maybe turn it into a proper language.

Curie is dynamically typed. It is native for performance but mostly to get back to the metal and understand what happens there. It is meant to support courses, workshops, talks, articles, experiments, etc. It is _not_ meant to be used for web programming. If you want to do that, please use Clojure instead.

One key feature is living in the repl, while being a scientific native language.

## Roadmap

1. A working repl, written in another language (Rust for example).
2. Emit bytecode for loading modules in the repl.
3. Emit assembly code.
4. Rewrite the compiler in curie, i.e. finish bootstrapping the compiler.

Later on, we could:

- Add a C foreign function interface (FFI).
- Rewrite the garbage collector.
- Play with parallelism and GPU.
- Add packaging tools and a repo.
- Add automatic documentation.

## Contributing

Push directly to master. If you break the build, just fix it. If you don't have write access to master, ping us.
