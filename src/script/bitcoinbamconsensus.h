// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Copyright (c) 2020 The BitcoinBam Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOINBAM_SCRIPT_BITCOINBAMCONSENSUS_H
#define BITCOINBAM_SCRIPT_BITCOINBAMCONSENSUS_H

#include <stdint.h>

#if defined(BUILD_BITCOINBAM_INTERNAL) && defined(HAVE_CONFIG_H)
#include <config/bitcoinbam-config.h>
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBBITCOINBAMCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define BITCOINBAMCONSENSUS_API_VER 1

typedef enum bitcoinbamconsensus_error_t
{
    bitcoinbamconsensus_ERR_OK = 0,
    bitcoinbamconsensus_ERR_TX_INDEX,
    bitcoinbamconsensus_ERR_TX_SIZE_MISMATCH,
    bitcoinbamconsensus_ERR_TX_DESERIALIZE,
    bitcoinbamconsensus_ERR_AMOUNT_REQUIRED,
    bitcoinbamconsensus_ERR_INVALID_FLAGS,
} bitcoinbamconsensus_error;

/** Script verification flags */
enum
{
    bitcoinbamconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    bitcoinbamconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    bitcoinbamconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    bitcoinbamconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    bitcoinbamconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    bitcoinbamconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    bitcoinbamconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    bitcoinbamconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = bitcoinbamconsensus_SCRIPT_FLAGS_VERIFY_P2SH | bitcoinbamconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               bitcoinbamconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | bitcoinbamconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               bitcoinbamconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | bitcoinbamconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int bitcoinbamconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, bitcoinbamconsensus_error* err);

EXPORT_SYMBOL int bitcoinbamconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, bitcoinbamconsensus_error* err);

EXPORT_SYMBOL unsigned int bitcoinbamconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // BITCOINBAM_SCRIPT_BITCOINBAMCONSENSUS_H
