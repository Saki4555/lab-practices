const InventoryCard = ({item, dataLength}) => {
  return (
    <div
      className={`flex bg-[#c9ebe8] rounded-2xl justify-center items-center  border-2 px-5 py-3 shadow-2xl flex-shrink-0 ${
        item.day ===  dataLength ? "bg-indigo-200" : ""
      }`}
    >
      <div className="p-4 font-medium space-y-1">
      <p className="">Day : {item.day} </p>
      <p className="w-fit">Inventory Level : {item.inventoryLevel}</p>
      <p>Demand : {item.demand}</p>
      <p>Shortage : {item.shortage}</p>
     {
      item?.orderQuantity > 0 && <div className="text-sm border border-black">
      <p>Order Quantity : {item?.orderQuantity}</p>
      <p>Lead-Time: {item?.leadTime}</p>
      <p>Order Number : {item?.orderCount}</p>
     
      </div>
     }

{item.orderDelivered && <p>Yes</p>}
      
      </div>
     
    </div>
  );
};

export default InventoryCard;
