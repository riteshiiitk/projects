public static void main(String[] args) 
{
    try
    {
        //colored image path
        BufferedImage colored_image = ImageIO.read(new File("D:\\logo.jpg"));
        //getting width and height of image
        double image_width = colored_image.getWidth();
        double image_height = colored_image.getHeight();
        BufferedImage img = colored_image;

        //drawing a new image
        BufferedImage bimg = new BufferedImage((int)image_width, (int)image_height, BufferedImage.TYPE_BYTE_GRAY);
        Graphics2D gg = bimg.createGraphics();
        gg.drawImage(img, 0, 0, img.getWidth(null), img.getHeight(null), null);

        //saving black and white image onto drive
        String temp = "logo in blackAndwhite.jpeg";
        File fi = new File("D:\\" + temp);
        ImageIO.write(bimg, "jpg", fi);

        //thinning by resizing gray scale image to desired eight and width
        BufferedImage bimg2 = new BufferedImage((int)image_width, (int)image_height, BufferedImage.TYPE_INT_ARGB);
        Graphics2D g2 = bimg2.createGraphics();

        // Perform your drawing here
        g2.setColor(Color.BLACK);
        g2.drawLine(0, 0, 200, 200);

       //saving thinned image onto drive
       String temp2 = "canny.png";
       File fi2 = new File("D:\\" + temp2);
       ImageIO.write(bimg2, "jpg", fi2);
       //g2.dispose();
    }
    catch (Exception e)
    {
        System.out.println(e);
