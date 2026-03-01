#!/usr/bin/env python3

class Plant:
    """
    Represents a plant object.

    Attributes:
        name (str): Plant's name
        height_cm (int): height in cm
        age_days (int): age in days
    """

    def __init__(self, name: str, height_cm: int, age_days: int):
        """
        Initializes the plant with name, height and age
        """
        self.name = name
        self.height_cm = height_cm
        self.age_days = age_days

    def grow(self, cm: int = 1) -> None:
        """
        Grow up the plant with a value in cm

        :param cm(int): height increment in cm (default is 1cm)
        """
        self.height_cm += cm

    def age(self, days: int = 1) -> None:
        """
        Grow up the plant with a value in days

        :param days(int): age increment in days (default is 1 day)
        """
        self.age_days += days

    def get_info(self) -> str:
        """
        Display the plant's information
        """
        return f"{self.name}: {self.height_cm}cm, {self.age_days} days old"


def simulate_week(plant: Plant, daily_growth: int = 1) -> None:
    """
    Simulate a week of growth for multiple plants

    :param plant: plant object
    :param daily_growth: height grow in cm per day

    Storing initial height and age in start_height and start_age
    Implement the growth for 7 days
    Display the information before and after growth.
    """
    start_height = plant.height_cm
    start_age = plant.age_days

    for _ in range(7):
        plant.grow(daily_growth)
        plant.age(1)

    print("=== Day 1 ===")
    print(f"{plant.name}: {start_height}cm, {start_age} days old")
    print("=== Day 7 ===")
    print(f"{plant.get_info()}")
    print(f"Growth this week: +{plant.height_cm - start_height}cm\n")


def main() -> None:
    rose = Plant("Rose", 25, 30)
    sunflower = Plant("Sunflower", 80, 45)
    cactus = Plant("Cactus", 15, 120)

    garden_plants = [rose, sunflower, cactus]

    for plant in garden_plants:
        simulate_week(plant, daily_growth=1)


if __name__ == "__main__":
    main()
