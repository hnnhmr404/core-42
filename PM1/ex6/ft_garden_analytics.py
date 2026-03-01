#!/usr/bin/env python3

class GardenUtils:
    """
    Utility class containing helper methods for garden-related validation
    """
    @staticmethod
    def validate_height(height):
        """
        Validates that a plant's height is a positive value.

        Args:
            height (int | float): The height to validate.

        Returns:
            bool: True if height is greater than 0, otherwise False.
        """
        return height > 0


class Plant:
    """
    Represents a basic plant with a name and height.

    Attributes:
        name (str): The name of the plant.
        height (int): The height of the plant in cm.
    """

    def __init__(self, name, height):
        """ Initializes a Plant object. """
        self.name = name
        self.height = height

    def grow(self):
        """
        Increases the plant's height by 1cm and prints a message.
        """
        self.height += 1
        print(f"{self.name} grew 1cm")

    def __str__(self):
        """
        Returns a string representation of the plant.

        Returns:
            str: Formatted plant name and height.
        """
        return f"{self.name}: {self.height}cm"


class FloweringPlant(Plant):
    """
    Represents a flowering plant that has a color and blooming state.

    Inherits fromL
        Plant
    """
    def __init__(self, name, height, color):
        """ Initializes a FloweringPlant object."""
        super().__init__(name, height)
        self.color = color
        self.blooming = True

    def __str__(self):
        """
        Returns a string representation of the flowering plant.
        """
        return (
            f"{super().__str__()}, "
            f"{self.color} flowers (blooming)"
        )


class PrizeFlower(FloweringPlant):
    """
    Represents a special flowering plant that awards prize points.

    Inherits from:
        FloweringPlant

    Attributes:
        prize_points (int): Points awarded for this prize flower.
    """

    def __init__(self, name, height, color, prize_points):
        """ Initializes a PrizeFlower object."""
        super().__init__(name, height, color)
        self.prize_points = prize_points

    def __str__(self):
        """
        Returns a string representation of the prize flower
        """
        return (
            f"{super().__str__()}, "
            f"Prize points: {self.prize_points}"
        )


class GardenManager:
    """
    Manages multiple gardens and provides global statistics and scoring.

    Attributes:
        garden (list): Class-level list containing all GardenManager instances.
    """

    gardens = []

    class GardenStats:
        """
        Provides statistics for a single garden.
        """

        def __init__(self, garden):
            """
            Initializes GardenStats for a specific garden

            Args:
                garden (Garden): The garden to analyze.
            """
            self.garden = garden

        def total_growth(self):
            """
            Calculates the total growth based on number of plants.

            Returns:
                int: Total growth value in cm.
            """
            return len(self.garden.plants)

        def plant_type_breakdown(self):
            """
            Counts different types of plants in the garden.

            Returns:
                tuple: (regular, flowering, prize) plant counts.
            """
            regular = flowering = prize = 0
            for plant in self.garden.plants:
                if isinstance(plant, PrizeFlower):
                    prize += 1
                elif isinstance(plant, FloweringPlant):
                    flowering += 1
                else:
                    regular += 1
            return regular, flowering, prize

        def print_stats(self):
            """
            Prints a summary of garden statistics, including plant counts
            and type breakdown.
            """
            regular, flowering, prize = self.plant_type_breakdown()
            print(
                f"Plants added: {len(self.garden.plants)}, "
                f"Total growth: {self.total_growth()}cm"
            )
            print(
                f"Plant types: {regular} regular, "
                f"{flowering} flowering, {prize} prize flowers"
            )

    def __init__(self):
        """
        Initializes a GardenManager and registers it globally.
        """
        self.managed_gardens = []
        GardenManager.gardens.append(self)

    def add_garden(self, garden):
        """
        Adds a garden to this manager.
        """
        self.managed_gardens.append(garden)

    @classmethod
    def create_garden_network(cls):
        """
        Creates a scoring network of all gardens managed by all managers.

        Each garden score is calculated as:
            sum of plant heights + any prize points.

            Returns:
                dict: Mapping of garden ownder names to their scores.
        """
        scores = {}
        for manager in cls.gardens:
            for garden in manager.managed_gardens:
                score = sum(
                    plant.height + getattr(plant, "prize_points", 0)
                    for plant in garden.plants
                )
                scores[garden.owner] = score
        return scores


class Garden:
    """
    Represents a garden owned by a person and containing plants.

    Attributes:
        ownder (str): Name of the garden owner.
        plants (list): List of plants in the garden.
        stats (GardenStats): Statistics object for this garden.
    """

    def __init__(self, owner):
        """
        Initializes a Garden object.
        """
        self.owner = owner
        self.plants = []
        self.stats = GardenManager.GardenStats(self)

    def add_plant(self, plant):
        """
        Adds a plant to the garden.
        """
        self.plants.append(plant)
        print(f"Added {plant.name} to {self.owner}'s garden")

    def grow_all(self):
        """
        Causes all plants in the garden to grow by 1cm.
        """
        print(f"{self.owner} is helping all plants grow...")
        for plant in self.plants:
            plant.grow()

    def report(self):
        """
        Prints a detailed report of the garden's plants and statistics.
        """
        print(f"=== {self.owner}'s Garden Report ===")
        print("Plants in garden:")
        for plant in self.plants:
            print(f"- {plant}")
        self.stats.print_stats()


def main() -> None:
    """
    Demonstrates the Garden Management System.
    """
    print("=== Garden Management System Demo ===\n")

    manager = GardenManager()

    alice_garden = Garden("Alice")
    bob_garden = Garden("Bob")

    manager.add_garden(alice_garden)
    manager.add_garden(bob_garden)

    alice_garden.add_plant(Plant("Oak Tree", 100))
    alice_garden.add_plant(FloweringPlant("Rose", 25, "red"))
    alice_garden.add_plant(PrizeFlower("Sunflower", 50, "yellow", 10))
    print()

    alice_garden.grow_all()
    print()
    alice_garden.report()
    print()

    print("Height validation test:", GardenUtils.validate_height(10))

    scores = GardenManager.create_garden_network()
    print(
        f"Garden scores - Alice: {scores.get('Alice', 0)}, "
        f"Bob: {scores.get('Bob', 0)}"
    )
    print(f"Total gardens managed: {len(GardenManager.gardens)}")


if __name__ == "__main__":
    main()
