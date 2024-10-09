// -*- mode:c++;indent-tabs-mode:nil;c-basic-offset:4;coding:utf-8 -*-
// vi: set et ft=cpp ts=4 sts=4 sw=4 fenc=utf-8 :vi
//
// Copyright 2024 Mozilla Foundation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "highlight.h"

#include <cstdio>
#include <cstdlib>

using namespace std::string_literals;

HighlightPython g_highlight;

void test(std::string input, std::string expect) {
    std::string got;
    g_highlight.feed(&got, input);
    if (got != expect) {
        fprintf(stderr,
                "error: highlighting failed\n"
                "\t   input: %`'s\n"
                "\texpected: %`'s\n"
                "\t     got: %`'s\n",
                input.c_str(), expect.c_str(), got.c_str());
        exit(1);
    }
}

void testf(std::string input, std::string expect) {
    std::string got;
    g_highlight.feed(&got, input);
    g_highlight.flush(&got);
    if (got != expect) {
        fprintf(stderr,
                "error: highlighting failed\n"
                "\t   input: %`'s\n"
                "\texpected: %`'s\n"
                "\t     got: %`'s\n",
                input.c_str(), expect.c_str(), got.c_str());
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    test("", "");
    test("d", "");
    test("ef ", ""s + KEYWORD + "def" + RESET + " ");
    test("yo # hi\nthere ", "yo "s + COMMENT + "# hi" + RESET + "\nthere ");
    testf("# sup", ""s + COMMENT + "# sup" + RESET);
    testf("de", "de");
    testf("def", ""s + KEYWORD + "def" + RESET);
    testf("/hi/", "/hi/");
    testf("x '' y", "x "s + STRING + "''" + RESET + " y");
    testf("x '''''' y", "x "s + STRING + "''''''" + RESET + " y");
    testf("x '''xxx''' y", "x "s + STRING + "'''xxx'''" + RESET + " y");
    testf("x '''xx'x''' y", "x "s + STRING + "'''xx'x'''" + RESET + " y");
    testf("x '''xx''x''' y", "x "s + STRING + "'''xx''x'''" + RESET + " y");
    testf("x \"\" y", "x "s + STRING + "\"\"" + RESET + " y");
    testf("x \"\"\"\"\"\" y", "x "s + STRING + "\"\"\"\"\"\"" + RESET + " y");
    testf("x \"\"\"xxx\"\"\" y", "x "s + STRING + "\"\"\"xxx\"\"\"" + RESET + " y");
    testf("x 'c' y", "x "s + STRING + "'c'" + RESET + " y");
    testf("x '\\'' y", "x "s + STRING + "'\\''" + RESET + " y");
    testf("x \"c\" y", "x "s + STRING + "\"c\"" + RESET + " y");
    testf("x \"\\\"\" y", "x "s + STRING + "\"\\\"\"" + RESET + " y");
}
