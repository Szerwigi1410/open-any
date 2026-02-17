# open-any
Open any file from linux terminal

---
Tired of needing to specify the program to open a file from your terminal? Ever wished something would just do it for you? Well then the program you are looking for is **open-any**

## How to use it?
just type `open <your-file-here>` and you are done! **Open-any** will figure out what program should it use based on the files extension for you!

## How to configure it?
Just edit the config file in `~/.config/open-any/config.txt`. The flag `--editConf` opens the config file in vim. `open --editConf`.

---

# Supported File Types

## Code Files
- .C
- .c
- .cc
- .cpp
- .cxx
- .h
- .hh
- .hpp
- .hxx
- .sh
- .bash
- .zsh
- .py
- .pyw
- .java
- .js
- .ts
- .rs
- .go
- .rb
- .php
- .cs
- .swift
- .kt
- .kts
- .scala
- .dart
- .lua
- .pl
- .r
- .m
- .mm
- .sql
- .asm

## Generic Text Files
- .txt

## Audio-Only Files
- .mp3
- .m4a
- .aac
- .wav
- .flac
- .ogg
- .opus
- .aiff
- .aif
- .wma
- .alac
- .ape
- .wv
- .tta
- .amr
- .mid
- .midi
- .dsf
- .dff
- .au
- .ra
- .voc

## Video Files
- .mp4
- .mov
- .mkv
- .avi

## Markdown
- .md

## Pictures
- .png
- .apng
- .jpg
- .jpeg
- .jpe
- .jfif

## GIMP
- .xcf

## Krita
- .kra

## Default Handler (vim by default)
- Any other file extension not listed above
 
> **NOTE:** **Open-any** currently does not support user-defined file extensions but im working on it. If you REALY need more extensions you can modify the source code and feel free to contribute!