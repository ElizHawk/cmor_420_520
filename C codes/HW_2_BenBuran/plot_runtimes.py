import numpy as np
import matplotlib.pyplot as plt

O0_runtimes = np.loadtxt("runtimes_O0.txt")
O3_runtimes = np.loadtxt("runtimes_O3.txt")
dimension_array = np.linspace(10,128,119)

plt.figure(figsize=(8, 6))
plt.plot(dimension_array, O0_runtimes, 'o-', label='gcc -O0 (no optimization)')
plt.plot(dimension_array, O3_runtimes, 's-', label='gcc -O3 (optimized)')
plt.xlabel("Matrix Dimension n", fontsize=12)
plt.ylabel("Runtime (seconds)", fontsize=12)
plt.title("Matrix Multiplication Runtime vs. Dimension", fontsize=14)
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()
plt.savefig("matrix_runtimes.png", dpi=300)
plt.show()


