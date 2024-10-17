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

#include <ctype.h>

#define NORMAL 0
#define WORD 1
#define QUOTE 2
#define QUOTE2 3
#define DQUOTE 4
#define SLASH 5
#define SLASH_SLASH 6
#define SLASH_STAR 7
#define SLASH_STAR_STAR 8
#define HASH 9
#define HASH_EXCLAIM 10
#define ATTRIB 11
#define BACKSLASH 64

HighlightRust::HighlightRust() {
}

HighlightRust::~HighlightRust() {
}

void HighlightRust::feed(std::string *r, std::string_view input) {
    int c;
    for (size_t i = 0; i < input.size(); ++i) {
        c = input[i] & 255;

        if (t_ & BACKSLASH) {
            t_ &= ~BACKSLASH;
            *r += c;
            if (t_ == QUOTE)
                t_ = QUOTE2;
            continue;
        } else if (c == '\\') {
            *r += c;
            t_ |= BACKSLASH;
            continue;
        }

        switch (t_) {

        Normal:
        case NORMAL:
            if (!isascii(c) || isalpha(c) || c == '_') {
                t_ = WORD;
                goto Word;
            } else if (c == '/') {
                t_ = SLASH;
            } else if (c == '#') {
                t_ = HASH;
            } else if (c == '\'') {
                t_ = QUOTE;
                *r += HI_STRING;
                *r += c;
            } else if (c == '"') {
                t_ = DQUOTE;
                *r += HI_STRING;
                *r += c;
            } else {
                *r += c;
            }
            break;

        Word:
        case WORD:
            if (!isascii(c) || isalpha(c) || isdigit(c) || c == '_' || c == '!') {
                word_ += c;
            } else {
                if (is_keyword_rust(word_.data(), word_.size())) {
                    *r += HI_KEYWORD;
                    *r += word_;
                    *r += HI_RESET;
                } else if (!word_.empty() && word_[word_.size() - 1] == '!') {
                    *r += HI_MACRO;
                    *r += word_;
                    *r += HI_RESET;
                } else {
                    *r += word_;
                }
                word_.clear();
                t_ = NORMAL;
                goto Normal;
            }
            break;

        case SLASH:
            if (c == '/') {
                *r += HI_COMMENT;
                *r += "//";
                t_ = SLASH_SLASH;
            } else if (c == '*') {
                *r += HI_COMMENT;
                *r += "/*";
                t_ = SLASH_STAR;
            } else {
                *r += '/';
                t_ = NORMAL;
                goto Normal;
            }
            break;

        case SLASH_SLASH:
            if (c == '\n') {
                *r += HI_RESET;
                *r += c;
                t_ = NORMAL;
            } else {
                *r += c;
            }
            break;

        case SLASH_STAR:
            *r += c;
            if (c == '*')
                t_ = SLASH_STAR_STAR;
            break;

        case SLASH_STAR_STAR:
            *r += c;
            if (c == '/') {
                *r += HI_RESET;
                t_ = NORMAL;
            } else if (c != '*') {
                t_ = SLASH_STAR;
            }
            break;

        case QUOTE:
            *r += c;
            if (c == '\'') {
                *r += HI_RESET;
                t_ = NORMAL;
            } else {
                t_ = QUOTE2;
            }
            break;

        case QUOTE2:
            if (c == '\'') {
                *r += c;
                *r += HI_RESET;
                t_ = NORMAL;
            } else {
                *r += HI_RESET;
                *r += c;
                t_ = NORMAL;
            }
            break;

        case DQUOTE:
            *r += c;
            if (c == '"') {
                *r += HI_RESET;
                t_ = NORMAL;
            }
            break;

        case HASH:
            if (c == '!') {
                t_ = HASH_EXCLAIM;
            } else if (c == '[') {
                *r += HI_ATTRIB;
                *r += "#[";
                t_ = ATTRIB;
            } else {
                *r += '#';
                t_ = NORMAL;
                goto Normal;
            }
            break;

        case HASH_EXCLAIM:
            if (c == '[') {
                *r += HI_ATTRIB;
                *r += "#![";
                t_ = ATTRIB;
            } else {
                *r += "#!";
                t_ = NORMAL;
                goto Normal;
            }
            break;

        case ATTRIB:
            *r += c;
            if (c == '[') {
                ++nest_;
            } else if (c == ']') {
                if (nest_) {
                    --nest_;
                } else {
                    *r += HI_RESET;
                    t_ = NORMAL;
                }
            }
            break;

        default:
            __builtin_unreachable();
        }
    }
}

void HighlightRust::flush(std::string *r) {
    t_ &= ~BACKSLASH;
    switch (t_) {
    case WORD:
        if (is_keyword_rust(word_.data(), word_.size())) {
            *r += HI_KEYWORD;
            *r += word_;
            *r += HI_RESET;
        } else if (!word_.empty() && word_[word_.size() - 1] == '!') {
            *r += HI_MACRO;
            *r += word_;
            *r += HI_RESET;
        } else {
            *r += word_;
        }
        word_.clear();
        break;
    case SLASH:
        *r += '/';
        break;
    case QUOTE:
    case QUOTE2:
    case DQUOTE:
    case ATTRIB:
    case SLASH_SLASH:
    case SLASH_STAR:
    case SLASH_STAR_STAR:
        *r += HI_RESET;
        break;
    case HASH:
        *r += '#';
        break;
    case HASH_EXCLAIM:
        *r += "#!";
        break;
    default:
        break;
    }
    nest_ = 0;
    t_ = NORMAL;
}
