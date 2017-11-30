NOTE: create minionDecorator abstract class that has a protected minion as a field, then
    an enchantedMinion class that inherits from this class which has an enchantment as its field,
    and calls runEffect after being constructed (runEffect will buff/debuff the minion based on enchantment name)