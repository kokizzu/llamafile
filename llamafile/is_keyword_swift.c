/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: gperf llamafile/is_keyword_swift.gperf  */
/* Computed positions: -k'1-3,$' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gperf@gnu.org>."
#endif

#line 1 "llamafile/is_keyword_swift.gperf"

#include <string.h>

#define TOTAL_KEYWORDS 218
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 31
#define MIN_HASH_VALUE 18
#define MAX_HASH_VALUE 637
/* maximum key range = 620, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash (register const char *str, register size_t len)
{
  static const unsigned short asso_values[] =
    {
      638, 638, 638, 638, 638, 638, 638, 638, 638, 638,
      638, 638, 638, 638, 638, 638, 638, 638, 638, 638,
      638, 638, 638, 638, 638, 638, 638, 638, 638, 638,
      638, 638, 638, 638, 638, 638, 638, 638, 638, 638,
      638, 638, 638, 638, 638, 638, 638, 638, 638, 638,
      638, 638, 638, 638, 638, 638, 638, 638, 638, 638,
      638, 638, 638, 638, 638,   0,   5,   0,   0, 638,
      638, 638, 638, 638, 638, 638, 638, 638,  30, 638,
       10, 638,   0,   5, 140,   0, 638, 638, 638, 638,
      638, 638, 638, 638, 638,  50, 638,  20, 249,  30,
        0,   5, 190, 174, 130, 125,   0, 115, 100, 250,
       20,  25,  95,   5,  15,  10,   0, 154, 140,  95,
      130,  25,  20, 638, 638, 638, 638, 638, 638, 638,
      638, 638, 638, 638, 638, 638, 638, 638, 638, 638,
      638, 638, 638, 638, 638, 638, 638, 638, 638, 638,
      638, 638, 638, 638, 638, 638, 638, 638, 638, 638,
      638, 638, 638, 638, 638, 638, 638, 638, 638, 638,
      638, 638, 638, 638, 638, 638, 638, 638, 638, 638,
      638, 638, 638, 638, 638, 638, 638, 638, 638, 638,
      638, 638, 638, 638, 638, 638, 638, 638, 638, 638,
      638, 638, 638, 638, 638, 638, 638, 638, 638, 638,
      638, 638, 638, 638, 638, 638, 638, 638, 638, 638,
      638, 638, 638, 638, 638, 638, 638, 638, 638, 638,
      638, 638, 638, 638, 638, 638, 638, 638, 638, 638,
      638, 638, 638, 638, 638, 638, 638, 638, 638, 638,
      638, 638, 638, 638, 638, 638
    };
  register unsigned int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[2]];
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[(unsigned char)str[1]];
      /*FALLTHROUGH*/
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval + asso_values[(unsigned char)str[len - 1]];
}

const char *
is_keyword_swift (register const char *str, register size_t len)
{
  static const char * const wordlist[] =
    {
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "set",
      "", "", "", "", "", "", "", "", "",
      "attached",
      "", "",
      "struct",
      "",
      "required",
      "",
      "derivative",
      "retroactive",
      "",
      "rethrows",
      "", "",
      "target",
      "as",
      "Sendable",
      "read",
      "",
      "return",
      "renamed",
      "",
      "transpose",
      "assignment",
      "addressWithOwner",
      "do",
      "", "", "", "",
      "addressWithNativeOwner",
      "",
      "associatedtype",
      "", "",
      "noDerivative",
      "noescape",
      "", "",
      "static",
      "",
      "try",
      "case",
      "actor",
      "scoped",
      "_RefCountedObject",
      "Any",
      "none",
      "_read",
      "nonisolated",
      "reasync",
      "associativity",
      "canImport",
      "", "",
      "dynamic",
      "_BridgeObject",
      "_UnknownLayout",
      "_semantics",
      "",
      "consume",
      "continue",
      "",
      "async",
      "convenience",
      "",
      "any",
      "_dynamicReplacement",
      "", "", "",
      "accesses",
      "", "",
      "_typeEraser",
      "noasync",
      "", "",
      "convention",
      "", "",
      "let",
      "_documentation",
      "deprecated",
      "_const",
      "_nonSendable",
      "wrt",
      "", "", "", "",
      "__shared",
      "_PackageDescription",
      "",
      "repeat",
      "_NativeClass",
      "_NativeRefCountedObject",
      "else",
      "_compilerInitialized",
      "_noMetadata",
      "", "",
      "dependsOn",
      "_originallyDefinedIn",
      "didSet",
      "__owned",
      "", "",
      "__setter_access",
      "deinit",
      "", "",
      "typealias",
      "await",
      "",
      "discard",
      "", "", "",
      "distributed",
      "is",
      "operator",
      "open",
      "", "", "",
      "indirect",
      "preconcurrency",
      "introduced",
      "",
      "package",
      "Protocol",
      "then",
      "yield",
      "throws",
      "", "",
      "extension",
      "class",
      "_Class",
      "in",
      "isolated",
      "lazy",
      "",
      "_specialize",
      "reverse",
      "_private",
      "_spi_available",
      "inout",
      "", "",
      "true",
      "copy",
      "_alignment",
      "",
      "get",
      "override",
      "_optimize",
      "catch",
      "_cdecl",
      "", "",
      "each",
      "autoclosure",
      "_swift_native_objc_runtime_base",
      "",
      "var",
      "available",
      "unsafe",
      "",
      "_expose",
      "", "", "",
      "exclusivity",
      "default",
      "",
      "sourceFile",
      "cType",
      "unowned",
      "unsafeAddress",
      "_projectedValueProperty",
      "",
      "unavailable",
      "", "",
      "unchecked",
      "unsafeMutableAddress",
      "defer",
      "sending",
      "availability",
      "",
      "_TrivialAtMost",
      "", "", "",
      "_version",
      "_TrivialStride",
      "precedencegroup",
      "",
      "escaping",
      "optional",
      "safe",
      "", "", "", "",
      "witness_method",
      "swift",
      "",
      "forward",
      "exported",
      "weak",
      "where",
      "", "",
      "protocol",
      "spiModule",
      "throw",
      "",
      "private",
      "for",
      "lowerThan",
      "nonmutating",
      "prefix",
      "",
      "internal",
      "line",
      "",
      "inline",
      "",
      "consuming",
      "", "", "",
      "_underlyingVersion",
      "_effects",
      "kind",
      "",
      "linear",
      "postfix",
      "",
      "Type",
      "", "", "",
      "_forward",
      "init",
      "_unavailableFromAsync",
      "",
      "message",
      "",
      "super",
      "",
      "_local",
      "",
      "metadata",
      "_spi",
      "",
      "module",
      "", "",
      "_consuming",
      "",
      "initializes",
      "",
      "obsoleted",
      "some",
      "", "",
      "_linear",
      "",
      "left",
      "", "", "", "",
      "Self",
      "",
      "modify",
      "",
      "objc",
      "self",
      "visibility",
      "backDeployed",
      "",
      "_Trivial",
      "",
      "__consuming",
      "", "", "",
      "right",
      "false",
      "", "", "", "", "", "",
      "willSet",
      "compiler",
      "",
      "macro",
      "", "", "",
      "differentiable",
      "_move",
      "", "", "", "", "", "", "", "", "",
      "_objcRuntimeName",
      "", "",
      "nil",
      "", "", "", "",
      "guard",
      "",
      "_backDeploy",
      "",
      "_modify",
      "spi",
      "",
      "while",
      "", "",
      "_objcImplementation",
      "", "",
      "switch",
      "", "", "", "", "", "", "", "", "",
      "", "", "",
      "_opaqueReturnTypeOf",
      "", "", "", "", "", "", "", "", "",
      "break",
      "", "", "", "", "", "",
      "freestanding",
      "",
      "func",
      "", "", "", "", "", "", "", "",
      "of",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "",
      "subscript",
      "",
      "file",
      "",
      "_borrow",
      "", "", "", "",
      "fileprivate",
      "",
      "enum",
      "", "", "", "", "", "",
      "final",
      "",
      "mutableAddressWithOwner",
      "", "", "",
      "_implements",
      "",
      "mutableAddressWithNativeOwner",
      "", "",
      "fallthrough",
      "", "", "",
      "before",
      "", "", "",
      "higherThan",
      "", "", "", "", "", "", "", "", "",
      "",
      "infix",
      "",
      "borrowing",
      "", "", "",
      "import",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "",
      "block",
      "", "", "", "", "", "", "", "", "",
      "", "", "",
      "if",
      "_borrowing",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "",
      "public",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "",
      "mutating",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "",
      "_mutating"
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          register const char *s = wordlist[key];

          if (*str == *s && !strncmp (str + 1, s + 1, len - 1) && s[len] == '\0')
            return s;
        }
    }
  return 0;
}
