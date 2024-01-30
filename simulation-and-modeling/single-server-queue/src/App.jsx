
import bg from './assets/background-2.jpeg';
import { CustomerArrival } from './components/CustomerArrival';

const App = () => {
  return (
    <div style={{
      backgroundImage: `url(${bg})`,
    }} className="min-h-[100vh]">
      <CustomerArrival></CustomerArrival>
      
    </div>
  );
};

export default App;
