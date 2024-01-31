import { useState, useEffect } from 'react';

export function InventorySimulator() {

  const [inventory, setInventory] = useState(5);
  const [day, setDay] = useState(1);

  useEffect(() => {
    const interval = setInterval(() => {
      if (day > 30) {
        clearInterval(interval);
        return;
      }

      const demand = Math.floor(Math.random() * 4) + 1; 
      setInventory(prev => prev - demand);

      if (inventory < 3) {
        setTimeout(() => {
          setInventory(prev => prev + 10);
        }, 15 * 1000);
      }

      if (inventory < 0) {
        setTimeout(() => {
          setInventory(prev => prev + 10);
        }, 5 * 1000); 
      }

      setDay(day + 1);
    }, 5000);

    return () => clearInterval(interval);

  }, [day, inventory]);

  return (
    <div>
      <h1>Inventory: {inventory}</h1>
      <h2>Day: {day}</h2>
    </div>
  );

}