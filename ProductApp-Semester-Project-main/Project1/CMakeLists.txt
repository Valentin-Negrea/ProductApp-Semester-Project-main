cmake_minimum_required(VERSION 3.25)
project(lab9-10)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab9-10
        main.cpp
        Entitate.cpp
        EntitateRepo.cpp
        EntitateService.cpp
        tesEntitate.cpp
        testeRepo.cpp
        testeService.cpp
        UI.cpp
        Entitate.h
        EntitateRepo.h
        EntitateService.h
        tesEntitate.h
        testeRepo.h
        testeService.h
        UI.h
        FileRepo.cpp
        FileRepo.h
        Colectie.cpp
        Colectie.h

        PretValidator.cpp PretValidator.h CodValidator.cpp CodValidator.h NumeValidator.cpp NumeValidator.h CodeException.h)
