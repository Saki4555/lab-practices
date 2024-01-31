import {
    BarChart,
    Bar,
    XAxis,
    YAxis,
    CartesianGrid,
    Tooltip,
    Legend,
    ReferenceLine,
    ResponsiveContainer,
  } from 'recharts';

const InventoryBarChart = ({inventoryData}) => {
    console.log(inventoryData);
   
      return (
        <ResponsiveContainer width="100%" height={300}>
          <BarChart
            width={700}
            height={300}
            data={inventoryData}
            margin={{
              top: 5,
              right: 30,
              left: 20,
              bottom: 5,
            }}
            
          >
            <CartesianGrid strokeDasharray="3 3" />
            <XAxis dataKey="day" />
            <YAxis />
            <Tooltip />
            <Legend />
            
            <ReferenceLine y={0} stroke="#000" />
            <Bar dataKey="inventoryLevel" fill="#8884d8" />
            <Bar dataKey="shortage" fill="#FC2947" />
          </BarChart>
        </ResponsiveContainer>
      );
};

export default InventoryBarChart;