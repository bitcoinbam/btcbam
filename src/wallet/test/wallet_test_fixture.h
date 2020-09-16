// Copyright (c) 2016-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOINBAM_WALLET_TEST_WALLET_TEST_FIXTURE_H
#define BITCOINBAM_WALLET_TEST_WALLET_TEST_FIXTURE_H

#include <test/test_bitcoinbam.h>

#include <wallet/wallet.h>

#include <memory>

/** Testing setup and teardown for wallet.
 */
struct WalletTestingSetup: public TestingSetup {
    explicit WalletTestingSetup(const std::string& chainName = CBaseChainParams::MAIN);
    ~WalletTestingSetup();

    CWallet m_wallet;
};

#endif // BITCOINBAM_WALLET_TEST_WALLET_TEST_FIXTURE_H
