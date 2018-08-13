# ft_ssl

OpenSSL is a cryptographic toolkit library written C that is used to secure communications
over computer networks. It implements the Secure Sockets Layer (SSL) and
Transport Layer Security (TLS) network protocols to protect against eavesdropping
and verify identities during network communication. ft_ssl will try to recreatefrom scratch parts of the OpenSSL
functionalities. 

## message diggest algoritms

```
. md5
. sha256
. sha512
```

### Installing

```
make
```

## Running the tests

Edit $TEST variable in test.sh file.
```
sh test.sh
```

# Usage

- Hash from file :
```
./ft_ssl md5 file
```
- Hash from command line :
```
./ft_ssl md5 -s "some text"
```
- Hash from STDIN :
```
echo -n "some text" | ./ft_ssl md5
```

## Flags
```
• -p, echo STDIN to STDOUT and append the checksum to STDOUT
• -q, quiet mode
• -r, reverse the format of the output.
• -s, print the sum of the given string
```


