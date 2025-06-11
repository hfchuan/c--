import numpy as np
from scipy.linalg import lstsq

# 已知的点对 (x, y) 和对应的 (x', y')  原坐标系的点
src_points = np.array([
    [x1, y1],
    [x2, y2],
    [x3, y3]
])


# 目标坐标系的点
dst_points = np.array([
    [x1p, y1p],
    [x2p, y2p],
    [x3p, y3p]
])

# 构造矩阵 A 和 b 来解决 Ax = b
# A = np.zeros((6, 6))  # 6个未知数
# b = np.zeros(6)

A = []
b = []

# 填充 A 和 b
# for i in range(len(src_points)):
#     A[i*2, 0] = src_points[i, 0]
#     A[i*2, 1] = src_points[i, 1]
#     A[i*2, 2] = 1
#     A[i*2+1, 3] = src_points[i, 0]
#     A[i*2+1, 4] = src_points[i, 1]
#     A[i*2+1, 5] = 1
    
#     b[i*2] = dst_points[i, 0]
#     b[i*2+1] = dst_points[i, 1]


for i in range(len(src_points)):
    x, y = src_points[i]
    x_prime, y_prime = dst_points[i]
    A.append([x, y, 1, 0, 0, 0])  # 对应于a11, a12, t_x
    A.append([0, 0, 0, x, y, 1])  # 对应于a21, a22, t_y
    b.append(x_prime)
    b.append(y_prime)

A = np.array(A)
b = np.array(b)

# 使用最小二乘法求解
transform_params, _, _, _ = lstsq(A, b)

# 提取变换参数
a11, a12, t_x, a21, a22, t_y = transform_params

print(f"Transformation parameters:")
print(f"a11: {a11}, a12: {a12}, t_x: {t_x}")
print(f"a21: {a21}, a22: {a22}, t_y: {t_y}")



# 变换矩阵（假设已经计算得出）
a11, a12, t_x = 1.0, 0.0, 2.0  # 示例
a21, a22, t_y = 0.0, 1.0, 3.0  # 示例

# 定义变换矩阵
transformation_matrix = np.array([
    [a11, a12, t_x],
    [a21, a22, t_y]
])

# 需要变换的点 (x, y)
point = np.array([4, 5])

# 将点变换成齐次坐标形式 (x, y, 1)
homogeneous_point = np.append(point, 1)

# 使用矩阵乘法进行仿射变换
transformed_point = np.dot(transformation_matrix, homogeneous_point)

# 提取变换后的坐标 (x', y')
x_prime, y_prime = transformed_point[0], transformed_point[1]

# 输出变换后的点
print(f"Original point: ({point[0]}, {point[1]})")
print(f"Transformed point: ({x_prime}, {y_prime})")