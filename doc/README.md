BitcoinBam Core
=============

Setup
---------------------
BitcoinBam Core is the original BitcoinBam client and it builds the backbone of the network. It downloads and, by default, stores the entire history of BitcoinBam transactions (which is currently more than 100 GBs); depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more.

To download BitcoinBam Core, visit [bitcoinbamcore.org](https://bitcoinbamcore.org/en/releases/).

Running
---------------------
The following are some helpful notes on how to run BitcoinBam Core on your native platform.

### Unix

Unpack the files into a directory and run:

- `bin/bitcoinbam-qt` (GUI) or
- `bin/bitcoinbamd` (headless)

### Windows

Unpack the files into a directory, and then run bitcoinbam-qt.exe.

### macOS

Drag BitcoinBam Core to your applications folder, and then run BitcoinBam Core.

### Need Help?

* See the documentation at the [BitcoinBam Wiki](https://en.bitcoinbam.it/wiki/Main_Page)
for help and more information.
* Ask for help on [#bitcoinbam](http://webchat.freenode.net?channels=bitcoinbam) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net?channels=bitcoinbam).
* Ask for help on the [BitcoinBamTalk](https://bitcoinbamtalk.org/) forums, in the [Technical Support board](https://bitcoinbamtalk.org/index.php?board=4.0).

Building
---------------------
The following are developer notes on how to build BitcoinBam Core on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [Dependencies](dependencies.md)
- [macOS Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-windows.md)
- [OpenBSD Build Notes](build-openbsd.md)
- [NetBSD Build Notes](build-netbsd.md)
- [Gitian Building Guide](gitian-building.md)

Development
---------------------
The BitcoinBam repo's [root README](/README.md) contains relevant information on the development process and automated testing.

- [Developer Notes](developer-notes.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Source Code Documentation (External Link)](https://dev.visucore.com/bitcoinbam/doxygen/)
- [Translation Process](translation_process.md)
- [Translation Strings Policy](translation_strings_policy.md)
- [Travis CI](travis-ci.md)
- [Unauthenticated REST Interface](REST-interface.md)
- [Shared Libraries](shared-libraries.md)
- [BIPS](bips.md)
- [Dnsseed Policy](dnsseed-policy.md)
- [Benchmarking](benchmarking.md)

### Resources
* Discuss on the [BitcoinBamTalk](https://bitcoinbamtalk.org/) forums, in the [Development & Technical Discussion board](https://bitcoinbamtalk.org/index.php?board=6.0).
* Discuss project-specific development on #bitcoinbam-core-dev on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net/?channels=bitcoinbam-core-dev).
* Discuss general BitcoinBam development on #bitcoinbam-dev on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net/?channels=bitcoinbam-dev).

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Fuzz-testing](fuzzing.md)
- [Reduce Traffic](reduce-traffic.md)
- [Tor Support](tor.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)
- [ZMQ](zmq.md)

License
---------------------
Distributed under the [MIT software license](/COPYING).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](https://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
