Auto-generated C99 Wrapper for OpenUSD

# Building
## Prerequisites
You must have [babble](https://github.com/anderslanglands/babble) installed, either from a release binary distribution or by building and installing from source. Currently relies on babble-0.4 and tested with OpenUSD 23.08

## Building from source

```sh
cmake -B build -G Ninja -DCMAKE_PREFIX_PATH="<path to babble>;<path to openusd>;" -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

Then to run the test program:
```sh
./build/usd-c-test01 test01.usda
```

And you should see output like:
```sh
/
/World
  proxyPrim
  purpose TfToken "default"
  testFloat float 3.141590
  visibility TfToken "inherited"
  xformOpOrder
# ...
```

The test program itself using the generated wraper API looks like:
```c
    // Open the given stage and check that it opened successfully
    usd_StageRefPtr_t* stage_ref = NULL;
    usd_Stage_Open(argv[1], usd_StageInitialLoadSet_LoadAll, &stage_ref);

    bool is_invalid = false;
    usd_StageRefPtr_is_invalid(stage_ref, &is_invalid);
    if (is_invalid) {
        printf("failed to open stage \"%s\"\n", argv[1]);
    }
```
