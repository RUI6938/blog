import numpy as np
import matplotlib.pyplot as plt
from skimage import io
from skimage.color import rgb2hsv

# 读取图像
image_path = 'lenna512color.bmp'
img = io.imread(image_path)

# 显示原始图像
def show_original():
    plt.figure(figsize=(6, 6))
    plt.imshow(img)
    plt.title('Original Image')
    plt.axis('off')
    plt.show()

# 显示 RGB 三个通道图像
def show_rgb_channels():
    fig, axes = plt.subplots(1, 3, figsize=(15, 5))
    axes[0].imshow(img[:, :, 0], cmap='gray')
    axes[0].set_title('Red Channel')
    axes[0].axis('off')
    axes[1].imshow(img[:, :, 1], cmap='gray')
    axes[1].set_title('Green Channel')
    axes[1].axis('off')
    axes[2].imshow(img[:, :, 2], cmap='gray')
    axes[2].set_title('Blue Channel')
    axes[2].axis('off')
    plt.show()

# 转换为 HSI 并显示三个通道图像
def show_hsi_channels():
    hsv_img = rgb2hsv(img)
    hue = hsv_img[:, :, 0]
    saturation = hsv_img[:, :, 1]
    intensity = hsv_img[:, :, 2]
    fig, axes = plt.subplots(1, 3, figsize=(15, 5))
    axes[0].imshow(hue, cmap='hsv')
    axes[0].set_title('Hue Channel')
    axes[0].axis('off')
    axes[1].imshow(saturation, cmap='gray')
    axes[1].set_title('Saturation Channel')
    axes[1].axis('off')
    axes[2].imshow(intensity, cmap='gray')
    axes[2].set_title('Intensity Channel')
    axes[2].axis('off')
    plt.show()

# 转换为灰度图像并显示
def show_gray_image():
    gray = np.dot(img[..., :3], [0.2989, 0.5870, 0.1140])
    plt.figure(figsize=(6, 6))
    plt.imshow(gray, cmap='gray')
    plt.title('Gray Image')
    plt.axis('off')
    plt.show()

# 转换为二值图像并显示
def show_binary_image():
    gray_img = np.dot(img[..., :3], [0.2989, 0.5870, 0.1140])
    threshold = 0.5
    binary = np.where(gray_img > threshold, 1, 0)
    plt.figure(figsize=(6, 6))
    plt.imshow(binary, cmap='gray')
    plt.title('Binary Image')
    plt.axis('off')
    plt.show()

show_original()
show_rgb_channels()
show_hsi_channels()
show_gray_image()
show_binary_image()