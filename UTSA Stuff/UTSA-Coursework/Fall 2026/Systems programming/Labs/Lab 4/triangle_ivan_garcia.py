import math
# Ivan Garcia eaa108        
# our task is to design a Python3 class that models an isosceles triangle. However, this is by no means a
# simple class. The novelty of this implementation lies in its ability to automatically calculate and update
# multiple parameters on the fly, which are derived from the triangle’s base and height.


class Triangle:
    def __init__(self, base, height):
        #Takes two parameters, width and height. To build a new rectangle. This
        #method automatically updates all the triangle’s data attributes.
        self.base = base
        self.height = height
        self.side = self.calc_side()
        self.area = self.calc_area()
        self.perimeter = self.calc_perimeter()
        self.alpha = math.degrees(math.asin(self.height / self.side))
        self.beta = 180 - (2 * self.alpha)

    def set_base(self, base):
        #Change the current length value. New length must be greater than 0. 
        # This method automatically updates all the triangle’s data attributes.
        if base > 0:
            self.base = base
            self.side = self.calc_side()
            self.area = self.calc_area()
            self.perimeter = self.calc_perimeter()
            self.alpha = math.degrees(math.asin(self.height / self.side))
            self.beta = 180 - (2 * self.alpha)

    def set_height(self, height):
        #Change the current height value. New height must be greater than 0. 
        # This method automatically updates all the triangle’s data attributes.
        if height > 0:
            self.height = height
            self.side = self.calc_side()
            self.area = self.calc_area()
            self.perimeter = self.calc_perimeter()
            self.alpha = math.degrees(math.asin(self.height / self.side))
            self.beta = 180 - (2 * self.alpha)

    def calc_side(self):
        # compute and return the current value of each of the two lateral sides of the
        # triangle (You only return one value)
        side = math.hypot(self.base / 2, self.height)
        return side

    def calc_perimeter(self):
        #Compute and return the current value of the perimeter.
        perimeter = (2 * self.side) + self.base
        return perimeter

    def calc_area(self):
        #Compute and return the current value of the triangle’s area.
        area = (self.base * self.height) / 2
        return area

    def calc_alpha(self):
        #Compute and return the current value of the angle alpha
        alpha = math.degrees(math.asin(self.height/self.side))
        return alpha

    def calc_beta(self):
        #Compute and return the current value of the angle beta.
        beta = 180 - (2 * self.alpha)
        return beta

    def print_all(self) -> None:
        print(f"------------------------------")
        print(f"base : {self.base}")
        print(f"height : {self.height}")
        print(f"side : {self.side}")
        print(f"perimeter: {self.perimeter}")
        print(f"area : {self.area}")
        print(f"alpha : {self.alpha}")
        print(f"beta : {self.beta}")
        print(f"------------------------------")



#main (i know i don't need main but it feels weird to not have one)
#imma test the traingle class here
if __name__ == "__main__":
    triangle1 = Triangle(4, 3)
    triangle1.print_all()
    triangle1.set_base(6)
    triangle1.print_all()
    triangle1.set_height(5)
    triangle1.print_all()