import { useState, useEffect } from 'react';

export function BankQueue() {

  const [queue, setQueue] = useState([]);
  const [tellerFreeAt, setTellerFreeAt] = useState(0);

  useEffect(() => {
    const arriveInterval = setInterval(() => {
      // Add new customer to queue
      setQueue(prev => [...prev, {
        id: Date.now(),
        arriveTime: Date.now(),
        serviceTime: 3000 + Math.random() * 7000
      }]);
    }, 1000);

    return () => clearInterval(arriveInterval);

  }, []);

  useEffect(() => {
    if (tellerFreeAt < Date.now() && queue.length > 0) {
      const cust = queue[0];
      
      // Remove customer from queue  
      setQueue(prev => prev.slice(1));

      // Occupy teller for customer's service time
      setTellerFreeAt(Date.now() + cust.serviceTime);
    }
  }, [queue, tellerFreeAt]);

  return (
    <div>
      <h1>Bank Queue Sim</h1>
      
      {/* Show queue status */}
      <div>
        Queue Length: {queue.length}
        Avg Wait Time: {/* calculate average wait time*/}  
      </div>

      {/* Render queue visually */}
      <div className="queue">
        {queue.map(cust => (
          <div key={cust.id}>{cust.id}</div>
        ))}
      </div>
    </div>
  );
}