# FogML-Linux

Based on [FogML-Arduino](https://github.com/tszydlo/FogML-Arduino).

Usage:
- Compile C code: `pio run`,
- Generate data: `gendata/sim.py > data-sim-x24`,
- Run & redirect data: `.pio/build/linux_x86_64/program < data-sim-x24`,
- Observe the model learn for 16, then ok for 8, and fail for 8 iterations.
