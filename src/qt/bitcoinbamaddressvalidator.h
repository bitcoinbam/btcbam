// Copyright (c) 2011-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOINBAM_QT_BITCOINBAMADDRESSVALIDATOR_H
#define BITCOINBAM_QT_BITCOINBAMADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class BitcoinBamAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BitcoinBamAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** BitcoinBam address widget validator, checks for a valid bitcoinbam address.
 */
class BitcoinBamAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BitcoinBamAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // BITCOINBAM_QT_BITCOINBAMADDRESSVALIDATOR_H
