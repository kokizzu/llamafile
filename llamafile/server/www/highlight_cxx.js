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

const CXX_KEYWORDS = new Set([
  '_Float128',
  '_Float16',
  '_Float32',
  '_Float64',
  '__FUNCTION__',
  '__PRETTY_FUNCTION__',
  '__alignof',
  '__alignof__',
  '__asm',
  '__asm__',
  '__attribute',
  '__attribute__',
  '__bf16',
  '__builtin_offsetof',
  '__builtin_va_arg',
  '__complex',
  '__complex__',
  '__const',
  '__constant__',
  '__device__',
  '__extension__',
  '__float80',
  '__forceinline__',
  '__global__',
  '__host__',
  '__imag',
  '__imag__ ',
  '__inline',
  '__inline__',
  '__label__',
  '__launch_bounds__',
  '__null',
  '__real',
  '__real__ ',
  '__restrict',
  '__restrict__',
  '__shared__',
  '__signed',
  '__signed__',
  '__thread',
  '__typeof',
  '__volatile',
  '__volatile__ ',
  '__wur',
  'alignas',
  'alignof',
  'and',
  'and_eq',
  'asm',
  'atomic_cancel',
  'atomic_commit',
  'atomic_noexcept',
  'auto',
  'autotype',
  'bitand',
  'bitor',
  'blockDim',
  'blockIdx',
  'bool',
  'break',
  'case',
  'catch',
  'char',
  'char16_t',
  'char32_t',
  'char8_t',
  'class',
  'co_await',
  'co_return',
  'co_yield',
  'compl',
  'concept',
  'const',
  'const_cast',
  'consteval',
  'constexpr',
  'constinit',
  'continue',
  'decltype',
  'default',
  'delete',
  'do',
  'dontcallback',
  'dontthrow',
  'double',
  'dynamic_cast',
  'else',
  'enum',
  'explicit',
  'export',
  'extern',
  'float',
  'for',
  'forcealign',
  'forcealignargpointer',
  'forceinline',
  'friend',
  'goto',
  'gridDim',
  'hasatleast',
  'if',
  'inline',
  'int',
  'interruptfn',
  'libcesque',
  'long',
  'mallocesque',
  'memcpyesque',
  'mutable',
  'namespace',
  'new',
  'nocallersavedregisters',
  'noexcept',
  'nosideeffect',
  'not',
  'not_eq',
  'nullptr',
  'nullterminated',
  'operator',
  'or',
  'or_eq',
  'paramsnonnull',
  'printfesque',
  'private',
  'privileged',
  'protected',
  'public',
  'pureconst',
  'reallocesque',
  'reflexpr',
  'register',
  'reinterpret_cast',
  'relegated',
  'requires',
  'return',
  'returnsaligned',
  'returnsnonnull',
  'returnspointerwithnoaliases',
  'returnstwice',
  'scanfesque',
  'short',
  'signed',
  'sizeof',
  'static',
  'static_cast',
  'strftimeesque',
  'strlenesque',
  'struct',
  'switch',
  'synchronized',
  'template',
  'textwindows',
  'thatispacked',
  'this',
  'threadIdx',
  'thread_local',
  'throw',
  'try',
  'typedef',
  'typeid',
  'typename',
  'union',
  'unsigned',
  'using',
  'vallocesque',
  'virtual',
  'void',
  'volatile',
  'wchar_t',
  'while',
  'wontreturn',
  'xor',
  'xor_eq',
]);

class HighlightCxx extends HighlightC {
  constructor(delegate) {
    super(delegate);
    this.keywords = CXX_KEYWORDS;
  }
}

Highlighter.REGISTRY['c++'] = HighlightCxx;
Highlighter.REGISTRY['cxx'] = HighlightCxx;
Highlighter.REGISTRY['cpp'] = HighlightCxx;
Highlighter.REGISTRY['hpp'] = HighlightCxx;
Highlighter.REGISTRY['cc'] = HighlightCxx;
Highlighter.REGISTRY['cu'] = HighlightCxx;
