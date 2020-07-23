# SGX AES 256 Support

Port [Libsodium](https://download.libsodium.org/doc/) (1.0.18-stable, July 03, 2020) `AES-256-GCM` algorithm into Intel SGX enclaves.
It uses the CPU `rdrand` instruction for digital random number generation, please refer to `Enclave/randombytes.cpp` for details.

To go into other details, please refer to `Enclave/aead_aes256gcm.cpp`.

Note that AES-NI is claimed to be side-channel proof.

**Developer: Maxul Lee**

## About Sodium

Sodium is a modern, easy-to-use software library for encryption, decryption, signatures, password hashing and more.
Sodium is cross-platforms and cross-languages. It runs on a variety of compilers and operating systems, including Windows (with MinGW or Visual Studio, x86 and x86_64), iOS and Android. Javascript and WebAssembly versions are also available and are fully supported.
