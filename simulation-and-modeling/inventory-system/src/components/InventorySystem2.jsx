import  {useState, useEffect} from 'react';

function InventorySystem2() {

  const [inventory, setInventory] = useState({
    apples: 10,
    bananas: 5,  
    oranges: 15
  });

  useEffect(() => {
    const interval = setInterval(() => {
      simulateInventoryChanges();
    }, 1000);
    return () => clearInterval(interval);
  }, []);

  const simulateInventoryChanges = () => {
    const newInventory = {...inventory};

    // Simulate random sales
    Object.keys(newInventory).forEach(item => {
      newInventory[item] = Math.max(0, newInventory[item] - Math.floor(Math.random() * 5)); 
    });

    // Simulate random restocking
    Object.keys(newInventory).forEach(item => {
      newInventory[item] += Math.floor(Math.random() * 5);
    });

    setInventory(newInventory);
  }

  // Display inventory
  const renderedInventory = Object.entries(inventory).map(([item, quantity]) => (
    <div key={item}>{item}: {quantity}</div>
  ));

  return (
    <div>
      <h1>Inventory Simulator</h1>
      {renderedInventory}
    </div>
  );

}

export default InventorySystem2;