Shared Libraries
================

## bitcoinbamconsensus

The purpose of this library is to make the verification functionality that is critical to BitcoinBam's consensus available to other applications, e.g. to language bindings.

### API

The interface is defined in the C header `bitcoinbamconsensus.h` located in  `src/script/bitcoinbamconsensus.h`.

#### Version

`bitcoinbamconsensus_version` returns an `unsigned int` with the API version *(currently at an experimental `0`)*.

#### Script Validation

`bitcoinbamconsensus_verify_script` returns an `int` with the status of the verification. It will be `1` if the input script correctly spends the previous output `scriptPubKey`.

##### Parameters
- `const unsigned char *scriptPubKey` - The previous output script that encumbers spending.
- `unsigned int scriptPubKeyLen` - The number of bytes for the `scriptPubKey`.
- `const unsigned char *txTo` - The transaction with the input that is spending the previous output.
- `unsigned int txToLen` - The number of bytes for the `txTo`.
- `unsigned int nIn` - The index of the input in `txTo` that spends the `scriptPubKey`.
- `unsigned int flags` - The script validation flags *(see below)*.
- `bitcoinbamconsensus_error* err` - Will have the error/success code for the operation *(see below)*.

##### Script Flags
- `bitcoinbamconsensus_SCRIPT_FLAGS_VERIFY_NONE`
- `bitcoinbamconsensus_SCRIPT_FLAGS_VERIFY_P2SH` - Evaluate P2SH ([BIP16](https://github.com/bitcoinbam/bips/blob/master/bip-0016.mediawiki)) subscripts
- `bitcoinbamconsensus_SCRIPT_FLAGS_VERIFY_DERSIG` - Enforce strict DER ([BIP66](https://github.com/bitcoinbam/bips/blob/master/bip-0066.mediawiki)) compliance
- `bitcoinbamconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY` - Enforce NULLDUMMY ([BIP147](https://github.com/bitcoinbam/bips/blob/master/bip-0147.mediawiki))
- `bitcoinbamconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY` - Enable CHECKLOCKTIMEVERIFY ([BIP65](https://github.com/bitcoinbam/bips/blob/master/bip-0065.mediawiki))
- `bitcoinbamconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY` - Enable CHECKSEQUENCEVERIFY ([BIP112](https://github.com/bitcoinbam/bips/blob/master/bip-0112.mediawiki))
- `bitcoinbamconsensus_SCRIPT_FLAGS_VERIFY_WITNESS` - Enable WITNESS ([BIP141](https://github.com/bitcoinbam/bips/blob/master/bip-0141.mediawiki))

##### Errors
- `bitcoinbamconsensus_ERR_OK` - No errors with input parameters *(see the return value of `bitcoinbamconsensus_verify_script` for the verification status)*
- `bitcoinbamconsensus_ERR_TX_INDEX` - An invalid index for `txTo`
- `bitcoinbamconsensus_ERR_TX_SIZE_MISMATCH` - `txToLen` did not match with the size of `txTo`
- `bitcoinbamconsensus_ERR_DESERIALIZE` - An error deserializing `txTo`
- `bitcoinbamconsensus_ERR_AMOUNT_REQUIRED` - Input amount is required if WITNESS is used

### Example Implementations
- [NBitcoinBam](https://github.com/NicolasDorier/NBitcoinBam/blob/master/NBitcoinBam/Script.cs#L814) (.NET Bindings)
- [node-libbitcoinbamconsensus](https://github.com/bitpay/node-libbitcoinbamconsensus) (Node.js Bindings)
- [java-libbitcoinbamconsensus](https://github.com/dexX7/java-libbitcoinbamconsensus) (Java Bindings)
- [bitcoinbamconsensus-php](https://github.com/Bit-Wasp/bitcoinbamconsensus-php) (PHP Bindings)
