#!/usr/bin/env python3

class Plant:
    """
    Represents a plant object.

    Attributes:
        name (str): Plant's name
        height_cm (int): height in cm
        age_days (int): Age in days
    """
    def __init__(self, name: str, height_cm: int, age_days: int):
        """
        Initializes the plant with name, height and age.

        :param name: Plant's name
        :param height_cm: height in cm
        :param age_days: age in days
        """
        self.name = name
        self.height_cm = height_cm
        self.age_days = age_days

    def display_info(self) -> None:
        """
        Display the info for the plants
        """
        print(f"{self.name}: {self.height_cm}cm, {self.age_days} days old")


def main() -> None:
    rose = Plant("Rose", 25, 30)
    sunflower = Plant("Sunflower", 80, 45)
    cactus = Plant("Cactus", 15, 120)

    garden_plants = [rose, sunflower, cactus]

    print("=== Garden Plant Registry ===")
    for plant in garden_plants:
        plant.display_info()


if __name__ == "__main__":
    main()
