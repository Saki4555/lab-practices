🌐 Live Site
🔗 Check out the live demo (https://demandflow-inventory-simulation.netlify.app/)
## Features

### 📦 Inventory Management
- **Real-Time Inventory Tracking** – Monitors inventory levels and updates daily.
- **Dynamic Demand Simulation** – Uses `generateRandomDemand()` to mimic real-world demand fluctuations.
- **Automated Ordering System** – Places orders every 5 days if inventory is low.
- **Lead Time Simulation** – Implements `generateRandomLeadTime()` to introduce order delays.
- **Shortage Calculation** – Keeps track of shortages when demand exceeds available stock.
- **Order Delivery Handling** – Updates inventory when new orders arrive.
- **Day Progression** – Automatically increments the simulation day every second.

### 📊 Data Visualization
- **Inventory Status Cards** – Displays daily inventory levels, demand, shortages, and order status using `InventoryCard`.
- **Bar Chart Representation** – Visualizes inventory trends with `InventoryBarChart`.
- **Simulation Summary** – Shows an overview (`Description` component) at the end of the simulation (30 days).

### 💡 User Experience
- **Automatic Simulation** – Runs automatically without manual intervention.
- **Responsive Layout** – Adjusts UI dynamically based on simulation progress.
- **Scrollable Data View** – Enables horizontal scrolling for better visualization when days increase.
- **Simulation End Indicator** – Changes layout when the simulation is completed.

---

🚀 *This project provides a simple yet effective way to understand inventory management dynamics through simulation.*

