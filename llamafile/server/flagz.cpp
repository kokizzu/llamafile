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

#include "client.h"
#include "llama.cpp/llama.h"
#include "llamafile/llamafile.h"
#include "llamafile/server/json.h"

namespace lf {
namespace server {

bool
Client::flagz()
{
    jt::Json json;
    json["prompt"] = FLAG_prompt;
    json["no_display_prompt"] = FLAG_no_display_prompt;
    json["nologo"] = FLAG_nologo;
    json["temperature"] = FLAG_temperature;
    json["presence_penalty"] = FLAG_presence_penalty;
    json["frequency_penalty"] = FLAG_frequency_penalty;
    if (FLAG_seed == LLAMA_DEFAULT_SEED) {
        json["seed"] = nullptr;
    } else {
        json["seed"] = FLAG_seed;
    }
    dump_ = json.toStringPretty();
    dump_ += '\n';
    char* p = append_http_response_message(obuf_.p, 200);
    p = stpcpy(p, "Content-Type: application/json\r\n");
    return send_response(obuf_.p, p, dump_);
}

} // namespace server
} // namespace lf
