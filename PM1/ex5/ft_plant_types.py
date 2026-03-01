#!/usr/bin/env python3

class Plant:
    """
    Represent a plant object

    Attributes:
        name (str): Plant's name
        height (int): height in cm
        age (int): age in days
    """
    def __init__(self, name: str, height: int, age: int):
        self.name = name
        self.height = height
        self.age = age


class Flower(Plant):
    """
    Represent a Flower, which is a specific type of Plant with color
    and the ability to bloom.

    Attributes:
        color (str): Color of the plant
    """
    def __init__(self, name, height, age, color):
        """ Initializes a Flower object. """
        super().__init__(name, height, age)
        self.color = color

    def bloom(self):
        """ Display the ability to bloom """
        print(f"{self.name} is blooming beautifully!")

    def __str__(self):
        """
        return a human-readable string representation of the Flower object
        """
        return (
            f"{self.name} (Flower): {self.height}cm, "
            f"{self.age} days, {self.color} color"
        )


class Tree(Plant):
    """
    Represents a Tree, which is a specific type of Plant with trunk diameter
    and the ability to produce shade.

    Attributes:
        trunk_diameter (float): Diameter of the tree trunk in centimeter
    """
    def __init__(self, name, height, age, trunk_diameter):
        """ Initializes a Tree object. """
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def produce_shade(self):
        """
        Calculates and displays the approximate shade area produced by the tree

        The shade area is estimated using the trunk diameter multiplied by
        a constant factor (1.56). The result is displayed in square meters.
        """
        shade_area = self.trunk_diameter * 1.56
        print(f"{self.name} provides {int(shade_area)} square meters of shade")

    def __str__(self):
        """
        return a human-readable string representation of the Tree object
        """
        return (
            f"{self.name} (Tree): {self.height}cm, "
            f"{self.age} days, {self.trunk_diameter}cm diameter"
        )


class Vegetable(Plant):
    """
    Represents a Vegetable, which is a specific type of Plant
    with harvest season and nutritional value.

    Attributes:
        harvest_season (str): harvest season
        nutritional_value (str): nutritional value
    """
    def __init__(self, name, height, age, harvest_season, nutritional_value):
        """ Initializes a Vegetable object """
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    def nutrition(self):
        """ Display the nutrition value """
        print(f"{self.name} is rich in {self.nutritional_value}")

    def __str__(self):
        """
        return a human-readable string representation of the Vegetable object
        """
        return (
            f"{self.name} (Vegetable): {self.height}cm, "
            f"{self.age} days, {self.harvest_season} harvest"
        )


def main() -> None:
    """ Entry point of Specialized Plant Type Program """
    print("=== Garden Plant Types ===\n")

    flowers = [
        Flower("Rose", 25, 30, "red")
    ]

    trees = [
        Tree("Oak", 500, 1825, 50)
    ]

    vegetables = [
        Vegetable("Tomato", 80, 90, "summer", "vitamin C")
    ]

    for flower in flowers:
        print(flower)
        flower.bloom()
        print()

    for tree in trees:
        print(tree)
        tree.produce_shade()
        print()

    for veg in vegetables:
        print(veg)
        veg.nutrition()
        print()


if __name__ == "__main__":
    main()
