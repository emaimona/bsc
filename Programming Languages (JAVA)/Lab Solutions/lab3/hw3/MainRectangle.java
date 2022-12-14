class Rectangle {
    double x, y;
    double width, height;
    Point topLeft(){
        Point p = new Point();
        p.x = width >= 0 ? x : x + width;
        p.y = height >= 0 ? y + height : y;
        return p;
    }

    Point topRight(){
        Point p = new Point();
        p.x = width >= 0 ? x + width : x;
        p.y = height >= 0 ? y + height  : y;
        return p;
    }

    Point bottomLeft(){
        Point p = new Point();
        p.x = width >= 0 ? x : x + width;
        p.y = height >= 0 ? y : y + height;
        return p;
    }

    Point bottomRight(){
        Point p = new Point();
        p.x = width >= 0 ? x + width : x;
        p.y = height >= 0 ? y : y + height;
        return p;
    }
}

class MainRectangle
{
    public static void main(String[] args)
    {
        if( args.length < 4 ){
            System.out.println("Too few arguments, at least 4 numbers are needed.");
            return;
        }

        Rectangle first = new Rectangle();
        first.x = Integer.parseInt(args[0]);
        first.y = Integer.parseInt(args[1]);
        first.width = Integer.parseInt(args[2]);
        first.height = Integer.parseInt(args[3]);

        Point bottomLeft = first.bottomLeft();
        Point topRight = first.topRight();

        for (int i = 4; i+3 < args.length; i += 4)
        {
            Rectangle curr = new Rectangle();
            curr.x = Integer.parseInt(args[i]);
            curr.y = Integer.parseInt(args[i+1]);
            curr.width = Integer.parseInt(args[i+2]);
            curr.height = Integer.parseInt(args[i+3]);

            Point currentBottomLeft = curr.bottomLeft();
            Point currentTopRight = curr.topRight();
    
            if( bottomLeft.x > currentBottomLeft.x ){
                bottomLeft.x = currentBottomLeft.x;
            }
            if( bottomLeft.y > currentBottomLeft.y ){
                bottomLeft.y = currentBottomLeft.y;
            }
            if( topRight.x < currentTopRight.x ){
                topRight.x = currentTopRight.x;
            }
            if( topRight.y < currentTopRight.y ){
                topRight.y = currentTopRight.y;
            }
        }
    	System.out.println( "Bounding rectangle: " + bottomLeft.x + ";" + bottomLeft.y + " - " + topRight.x + ";" + topRight.y );
    }
}
