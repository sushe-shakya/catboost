#include "src_root.h"

#include <util/folder/pathsplit.h>
#include <library/unittest/registar.h>

Y_UNIT_TEST_SUITE(TestSourceRoot) {
    Y_UNIT_TEST(TestStrip) {
        // Reconstruct() converts "\" -> "/" on Windows
        const TString path = TPathSplit(__SOURCE_FILE_IMPL__.As<TStringBuf>()).Reconstruct();
        UNIT_ASSERT_EQUAL(path, "util" LOCSLASH_S "system" LOCSLASH_S "src_root_ut.cpp");
    }

    Y_UNIT_TEST(TestPrivateChopPrefixRoutine) {
        static constexpr const char str[] = ":\0:\0: It's unlikely that this string has an ARCADIA_ROOT as its prefix :\0:\0:";
        static constexpr const auto strStaticBuf = STATIC_BUF(str);
        UNIT_ASSERT_VALUES_EQUAL(AsStringBuf(str), ::NPrivate::StripRoot(strStaticBuf).As<TStringBuf>());
    }
}
