# A Simple Shared Librare Preloader for CSGO Linux

Wraps a connect syscall, and once it gets called 7 times, a hardcoded library gets loaded into CSGO.

The library will not be loaded in if /tmp/dumps directory is not owned by root.
