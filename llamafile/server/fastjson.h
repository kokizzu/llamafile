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

#pragma once
#include <__fwd/string_view.h>

namespace lf {
namespace server {

char*
encode_bool(char*, bool) noexcept;

char*
encode_json(char*, int) noexcept;

char*
encode_json(char*, long) noexcept;

char*
encode_json(char*, float) noexcept;

char*
encode_json(char*, double) noexcept;

char*
encode_json(char*, unsigned) noexcept;

char*
encode_json(char*, unsigned long) noexcept;

char*
encode_json(char*, const std::string_view) noexcept;

char*
encode_js_string_literal(char*, const std::string_view) noexcept;

} // namespace server
} // namespace lf
