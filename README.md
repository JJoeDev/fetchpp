# fetchpp

Fetchpp is meant to be a simple Linux system fetch tool.

Fetchpp is created using C++17, I would at some point like to do a complete overhaul because I am sure I can create a better code structure for it, but it works as expected.

![](images/void.png)

## Instalation

Fetchpp is currently not in any distro repos as of my knowledge so go ahead and follow these steps

```
$ git clone https://github.com/jjoedev/fetchpp
$ cd fetchpp
$ chmod +x install.sh
$ ./install.sh
```

To check and see if fetchpp is installed simply run the following command.

```
$ fetchpp
```

## Uninstalling

Fetchpp is installed as a single binary in `/usr/local/bin/fetchpp`

to uninstall it simply remove the binary

## Usage

Fetchpp comes with a couple of flags that control how fetchpp will display the output.

To get a helpful message of everything fetchpp can do simply run `$ fetchpp -h`

Personally I have the following in my bashrc file

```
fetchpp -l void -c MAGENTA
```
