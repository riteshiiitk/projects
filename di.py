import cv2
import numpy as np

# Read image
img = cv2.imread("lrq.pgm",0)

# Create structuring element
kernel = np.ones((3,3),np.uint8)

# dilate image
dilation = cv2.dilate(img, kernel, iterations=1)

# Show Image
cv2.imshow("dilated image",dilation)

# Save image
cv2.imwrite("dailate music.pgm",dilation)

cv2.waitKey(0)
cv2.destroyAllWindows()

