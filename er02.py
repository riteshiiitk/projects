import cv2
import numpy as np

# Read image
img = cv2.imread("lpq.pgm",0)

# Create structuring element
kernel = np.ones((3,3),np.uint8)

# Erode image
erosion = cv2.erode(img,kernel,iterations = 2)

# Show Image
cv2.imshow("Eroded image",erosion)

# Save image
cv2.imwrite("Eroded music.pgm",erosion)

cv2.waitKey(0)
cv2.destroyAllWindows()

