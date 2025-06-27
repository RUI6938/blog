import React, { useState, useEffect } from 'react';

// 主应用组件
const App = () => {
   // 状态管理
   const [activeTab, setActiveTab] = useState('dashboard'); // 当前激活的标签页
   const [vehicles, setVehicles] = useState([]); // 车辆列表
   const [renters, setRenters] = useState([]); // 租用人列表
   const [rentals, setRentals] = useState([]); // 租赁记录列表

   // 模拟生成唯一ID
   const generateUniqueId = () => Math.random().toString(36).substring(2, 9);

   // 车辆管理相关状态和函数
   const [newVehicle, setNewVehicle] = useState({
       model: '',
       brand: '',
       status: '空闲', // 默认状态
       remarks: ''
   });

   // 处理新车辆表单输入
   const handleNewVehicleChange = (e) => {
       setNewVehicle({ ...newVehicle, [e.target.name]: e.target.value });
   };

   // 添加新车辆
   const addVehicle = () => {
       if (newVehicle.model && newVehicle.brand) {
           setVehicles([...vehicles, { id: `VEH-${generateUniqueId()}`, qrCode: `QR-${generateUniqueId()}`, ...newVehicle }]);
           setNewVehicle({ model: '', brand: '', status: '空闲', remarks: '' });
           alert('车辆添加成功！');
       } else {
           alert('请填写车辆型号和品牌！');
       }
   };

   // 租用人管理相关状态和函数 (在租赁时录入)
   const [newRental, setNewRental] = useState({
       renterName: '',
       idNumber: '',
       phoneNumber: '',
       address: '',
       rentalPoint: '',
       vehicleId: '',
       rentalStartDate: '',
       rentalEndDate: '',
       photos: [] // 模拟照片存储
   });

   // 处理新租赁表单输入
   const handleNewRentalChange = (e) => {
       setNewRental({ ...newRental, [e.target.name]: e.target.value });
   };

   // 开始新租赁
   const startRental = () => {
       if (newRental.renterName && newRental.vehicleId && newRental.rentalStartDate && newRental.rentalEndDate) {
           // 检查车辆是否存在且空闲
           const vehicle = vehicles.find(v => v.id === newRental.vehicleId && v.status === '空闲');
           if (vehicle) {
               // 更新车辆状态为“租用中”
               setVehicles(vehicles.map(v => v.id === newRental.vehicleId ? { ...v, status: '租用中' } : v));

               // 添加租用人信息（如果不存在）
               const existingRenter = renters.find(r => r.idNumber === newRental.idNumber);
               if (!existingRenter) {
                   setRenters([...renters, {
                       id: `REN-${generateUniqueId()}`,
                       name: newRental.renterName,
                       idNumber: newRental.idNumber,
                       phoneNumber: newRental.phoneNumber,
                       address: newRental.address
                   }]);
               }

               // 添加租赁记录
               setRentals([...rentals, {
                   id: `RENT-${generateUniqueId()}`,
                   ...newRental,
                   rentalStatus: '租用中',
                   actualReturnDate: null,
                   swapHistory: []
               }]);
               setNewRental({
                   renterName: '', idNumber: '', phoneNumber: '', address: '', rentalPoint: '',
                   vehicleId: '', rentalStartDate: '', rentalEndDate: '', photos: []
               });
               alert('租赁开始成功！');
           } else {
               alert('车辆ID不存在或车辆未空闲！');
           }
       } else {
           alert('请填写所有必填的租赁信息！');
       }
   };

   // 处理退租
   const returnRental = (rentalId) => {
       const rentalToReturn = rentals.find(r => r.id === rentalId);
       if (rentalToReturn && rentalToReturn.rentalStatus === '租用中') {
           // 更新租赁记录状态和实际归还日期
           setRentals(rentals.map(r =>
               r.id === rentalId ? { ...r, rentalStatus: '已退租', actualReturnDate: new Date().toISOString().split('T')[0] } : r
           ));
           // 更新车辆状态为“空闲”
           setVehicles(vehicles.map(v =>
               v.id === rentalToReturn.vehicleId ? { ...v, status: '空闲' } : v
           ));
           alert('退租成功！');
       } else {
           alert('租赁记录不存在或已退租！');
       }
   };

   // 处理续租
   const renewRental = (rentalId, newEndDate) => {
       const rentalToRenew = rentals.find(r => r.id === rentalId);
       if (rentalToRenew && rentalToRenew.rentalStatus === '租用中') {
           setRentals(rentals.map(r =>
               r.id === rentalId ? { ...r, rentalEndDate: newEndDate } : r
           ));
           alert('续租成功！');
       } else {
           alert('租赁记录不存在或已退租，无法续租！');
       }
   };

   // 处理中途换车
   const swapVehicle = (rentalId, oldVehicleId, newVehicleId, reason) => {
       const rentalToSwap = rentals.find(r => r.id === rentalId);
       const newVeh = vehicles.find(v => v.id === newVehicleId && v.status === '空闲');

       if (rentalToSwap && rentalToSwap.rentalStatus === '租用中' && newVeh) {
           // 更新旧车辆状态为“空闲”
           setVehicles(vehicles.map(v => v.id === oldVehicleId ? { ...v, status: '空闲' } : v));
           // 更新新车辆状态为“租用中”
           setVehicles(vehicles.map(v => v.id === newVehicleId ? { ...v, status: '租用中' } : v));

           // 更新租赁记录
           setRentals(rentals.map(r =>
               r.id === rentalId ? {
                   ...r,
                   vehicleId: newVehicleId,
                   swapHistory: [...r.swapHistory, { oldVehicleId, newVehicleId, reason, timestamp: new Date().toLocaleString() }]
               } : r
           ));
           alert('换车成功！');
       } else {
           alert('换车失败：租赁记录不存在、未租用或新车辆ID不存在/未空闲。');
       }
   };

   // 报告数据
   const dailyRentalCount = rentals.filter(r =>
       r.rentalStatus === '租用中' &&
       r.rentalStartDate === new Date().toISOString().split('T')[0]
   ).length;

   const totalVehicles = vehicles.length;
   const scrappedVehicles = vehicles.filter(v => v.status === '报废').length;

   const getDailyExpiringUsers = () => {
       const today = new Date();
       return rentals.filter(rental => {
           const endDate = new Date(rental.rentalEndDate);
           return rental.rentalStatus === '租用中' &&
                  endDate.toDateString() === today.toDateString();
       });
   };

   const getUpcomingExpiringUsers = () => {
       const today = new Date();
       const tomorrow = new Date(today);
       tomorrow.setDate(today.getDate() + 1);
       const dayAfterTomorrow = new Date(today);
       dayAfterTomorrow.setDate(today.getDate() + 2);

       return rentals.filter(rental => {
           const endDate = new Date(rental.rentalEndDate);
           return rental.rentalStatus === '租用中' &&
                  (endDate.toDateString() === tomorrow.toDateString() ||
                   endDate.toDateString() === dayAfterTomorrow.toDateString());
       });
   };

   return (
       <div className="min-h-screen bg-gray-100 flex flex-col md:flex-row font-inter">
           {/* 侧边导航栏 */}
           <nav className="bg-white p-4 shadow-lg md:w-64">
               <h1 className="text-2xl font-bold text-gray-800 mb-6 text-center">后台管理</h1>
               <ul className="space-y-2">
                   <li>
                       <button
                           onClick={() => setActiveTab('dashboard')}
                           className={`w-full text-left px-4 py-2 rounded-lg transition duration-200 ${activeTab === 'dashboard' ? 'bg-blue-600 text-white shadow' : 'text-gray-700 hover:bg-gray-200'}`}
                       >
                           数据概览
                       </button>
                   </li>
                   <li>
                       <button
                           onClick={() => setActiveTab('vehicleManagement')}
                           className={`w-full text-left px-4 py-2 rounded-lg transition duration-200 ${activeTab === 'vehicleManagement' ? 'bg-blue-600 text-white shadow' : 'text-gray-700 hover:bg-gray-200'}`}
                       >
                           车辆管理
                       </button>
                   </li>
                   <li>
                       <button
                           onClick={() => setActiveTab('rentalManagement')}
                           className={`w-full text-left px-4 py-2 rounded-lg transition duration-200 ${activeTab === 'rentalManagement' ? 'bg-blue-600 text-white shadow' : 'text-gray-700 hover:bg-gray-200'}`}
                       >
                           租赁管理
                       </button>
                   </li>
                   <li>
                       <button
                           onClick={() => setActiveTab('renterManagement')}
                           className={`w-full text-left px-4 py-2 rounded-lg transition duration-200 ${activeTab === 'renterManagement' ? 'bg-blue-600 text-white shadow' : 'text-gray-700 hover:bg-gray-200'}`}
                       >
                           租用人信息
                       </button>
                   </li>
               </ul>
           </nav>

           {/* 主内容区域 */}
           <main className="flex-1 p-4 md:p-8 overflow-y-auto">
               {activeTab === 'dashboard' && (
                   <div className="bg-white p-6 rounded-xl shadow-lg">
                       <h2 className="text-3xl font-bold mb-6 text-gray-800">数据概览</h2>
                       <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-6 mb-8">
                           <div className="bg-gradient-to-br from-blue-500 to-indigo-600 text-white p-6 rounded-xl shadow-md">
                               <h3 className="text-xl font-semibold mb-2">今日新增租赁</h3>
                               <p className="text-4xl font-bold">{dailyRentalCount}</p>
                           </div>
                           <div className="bg-gradient-to-br from-green-500 to-teal-600 text-white p-6 rounded-xl shadow-md">
                               <h3 className="text-xl font-semibold mb-2">车辆总数</h3>
                               <p className="text-4xl font-bold">{totalVehicles}</p>
                           </div>
                           <div className="bg-gradient-to-br from-red-500 to-rose-600 text-white p-6 rounded-xl shadow-md">
                               <h3 className="text-xl font-semibold mb-2">报废车辆数</h3>
                               <p className="text-4xl font-bold">{scrappedVehicles}</p>
                           </div>
                       </div>

                       <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                           <div className="bg-white p-6 rounded-xl shadow-md border border-gray-200">
                               <h3 className="text-2xl font-semibold mb-4 text-gray-800">今日到期用户</h3>
                               {getDailyExpiringUsers().length > 0 ? (
                                   <ul className="space-y-3">
                                       {getDailyExpiringUsers().map(rental => (
                                           <li key={rental.id} className="bg-blue-50 p-3 rounded-lg flex justify-between items-center text-gray-700">
                                               <span>{rental.renterName} ({rental.phoneNumber}) - 车辆: {rental.vehicleId}</span>
                                               <span className="font-medium text-blue-700">今日到期</span>
                                           </li>
                                       ))}
                                   </ul>
                               ) : (
                                   <p className="text-gray-500">今日无到期用户。</p>
                               )}
                           </div>
                           <div className="bg-white p-6 rounded-xl shadow-md border border-gray-200">
                               <h3 className="text-2xl font-semibold mb-4 text-gray-800">未来2天到期提醒</h3>
                               {getUpcomingExpiringUsers().length > 0 ? (
                                   <ul className="space-y-3">
                                       {getUpcomingExpiringUsers().map(rental => (
                                           <li key={rental.id} className="bg-yellow-50 p-3 rounded-lg flex justify-between items-center text-gray-700">
                                               <span>{rental.renterName} ({rental.phoneNumber}) - 车辆: {rental.vehicleId}</span>
                                               <span className="font-medium text-yellow-700">
                                                   {new Date(rental.rentalEndDate).toLocaleDateString('zh-CN', {month: 'numeric', day: 'numeric'})} 到期
                                               </span>
                                           </li>
                                       ))}
                                   </ul>
                               ) : (
                                   <p className="text-gray-500">未来2天无到期用户。</p>
                               )}
                           </div>
                       </div>
                   </div>
               )}

               {activeTab === 'vehicleManagement' && (
                   <div className="bg-white p-6 rounded-xl shadow-lg">
                       <h2 className="text-3xl font-bold mb-6 text-gray-800">车辆管理</h2>

                       {/* 添加新车辆 */}
                       <div className="mb-8 p-6 bg-gray-50 rounded-xl shadow-sm border border-gray-200">
                           <h3 className="text-2xl font-semibold mb-4 text-gray-800">添加新车辆</h3>
                           <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
                               <input
                                   type="text"
                                   name="model"
                                   placeholder="车辆型号"
                                   value={newVehicle.model}
                                   onChange={handleNewVehicleChange}
                                   className="p-3 border border-gray-300 rounded-lg focus:ring-blue-500 focus:border-blue-500"
                               />
                               <input
                                   type="text"
                                   name="brand"
                                   placeholder="车辆品牌"
                                   value={newVehicle.brand}
                                   onChange={handleNewVehicleChange}
                                   className="p-3 border border-gray-300 rounded-lg focus:ring-blue-500 focus:border-blue-500"
                               />
                               <select
                                   name="status"
                                   value={newVehicle.status}
                                   onChange={handleNewVehicleChange}
                                   className="p-3 border border-gray-300 rounded-lg focus:ring-blue-500 focus:border-blue-500"
                               >
                                   <option value="空闲">空闲</option>
                                   <option value="租用中">租用中</option>
                                   <option value="维修中">维修中</option>
                                   <option value="报废">报废</option>
                               </select>
                               <textarea
                                   name="remarks"
                                   placeholder="备注"
                                   value={newVehicle.remarks}
                                   onChange={handleNewVehicleChange}
                                   rows="2"
                                   className="p-3 border border-gray-300 rounded-lg focus:ring-blue-500 focus:border-blue-500 col-span-1 md:col-span-2"
                               ></textarea>
                           </div>
                           <button
                               onClick={addVehicle}
                               className="mt-6 w-full bg-blue-600 text-white py-3 rounded-lg hover:bg-blue-700 transition duration-300 shadow-md"
                           >
                               添加车辆
                           </button>
                       </div>

                       {/* 车辆列表 */}
                       <h3 className="text-2xl font-semibold mb-4 text-gray-800">所有车辆</h3>
                       <div className="overflow-x-auto rounded-lg shadow-sm border border-gray-200">
                           <table className="min-w-full divide-y divide-gray-200">
                               <thead className="bg-gray-50">
                                   <tr>
                                       <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">车辆ID</th>
                                       <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">型号</th>
                                       <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">品牌</th>
                                       <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">状态</th>
                                       <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">二维码</th>
                                       <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">备注</th>
                                       <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">操作</th>
                                   </tr>
                               </thead>
                               <tbody className="bg-white divide-y divide-gray-200">
                                   {vehicles.map(vehicle => (
                                       <tr key={vehicle.id}>
                                           <td className="px-6 py-4 whitespace-nowrap text-sm font-medium text-gray-900">{vehicle.id}</td>
                                           <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-700">{vehicle.model}</td>
                                           <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-700">{vehicle.brand}</td>
                                           <td className="px-6 py-4 whitespace-nowrap text-sm">
                                               <span className={`px-2 inline-flex text-xs leading-5 font-semibold rounded-full ${
                                                   vehicle.status === '空闲' ? 'bg-green-100 text-green-800' :
                                                   vehicle.status === '租用中' ? 'bg-blue-100 text-blue-800' :
                                                   vehicle.status === '维修中' ? 'bg-yellow-100 text-yellow-800' :
                                                   'bg-red-100 text-red-800'
                                               }`}>
                                                   {vehicle.status}
                                               </span>
                                           </td>
                                           <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-700">{vehicle.qrCode}</td>
                                           <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-700">{vehicle.remarks}</td>
                                           <td className="px-6 py-4 whitespace-nowrap text-right text-sm font-medium">
                                               <button
                                                   onClick={() => {
                                                       const newStatus = prompt(`更新车辆 ${vehicle.id} 的状态 (空闲/租用中/维修中/报废):`, vehicle.status);
                                                       if (newStatus) {
                                                           setVehicles(vehicles.map(v =>
                                                               v.id === vehicle.id ? { ...v, status: newStatus } : v
                                                           ));
                                                       }
                                                   }}
                                                   className="text-indigo-600 hover:text-indigo-900 mr-4"
                                               >
                                                   编辑
                                               </button>
                                               <button
                                                   onClick={() => {
                                                       const confirmDelete = window.confirm(`确定要删除车辆 ${vehicle.id} 吗？`);
                                                       if (confirmDelete) {
                                                           setVehicles(vehicles.filter(v => v.id !== vehicle.id));
                                                           alert('车辆删除成功！');
                                                       }
                                                   }}
                                                   className="text-red-600 hover:text-red-900"
                                               >
                                                   删除
                                               </button>
                                           </td>
                                       </tr>
                                   ))}
                               </tbody>
                           </table>
                       </div>
                   </div>
               )}

               {activeTab === 'rentalManagement' && (
                   <div className="bg-white p-6 rounded-xl shadow-lg">
                       <h2 className="text-3xl font-bold mb-6 text-gray-800">租赁管理</h2>

                       {/* 开始新租赁 */}
                       <div className="mb-8 p-6 bg-gray-50 rounded-xl shadow-sm border border-gray-200">
                           <h3 className="text-2xl font-semibold mb-4 text-gray-800">开始新租赁</h3>
                           <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
                               <input type="text" name="renterName" placeholder="租用人姓名" value={newRental.renterName} onChange={handleNewRentalChange} className="p-3 border border-gray-300 rounded-lg" />
                               <input type="text" name="idNumber" placeholder="身份证号" value={newRental.idNumber} onChange={handleNewRentalChange} className="p-3 border border-gray-300 rounded-lg" />
                               <input type="text" name="phoneNumber" placeholder="手机号" value={newRental.phoneNumber} onChange={handleNewRentalChange} className="p-3 border border-gray-300 rounded-lg" />
                               <input type="text" name="address" placeholder="地址" value={newRental.address} onChange={handleNewRentalChange} className="p-3 border border-gray-300 rounded-lg" />
                               <input type="text" name="rentalPoint" placeholder="租赁点" value={newRental.rentalPoint} onChange={handleNewRentalChange} className="p-3 border border-gray-300 rounded-lg" />
                               <input type="text" name="vehicleId" placeholder="车辆ID (例如: VEH-xxxxx)" value={newRental.vehicleId} onChange={handleNewRentalChange} className="p-3 border border-gray-300 rounded-lg" />
                               <label className="flex items-center text-gray-700">
                                   租赁开始日期:
                                   <input type="date" name="rentalStartDate" value={newRental.rentalStartDate} onChange={handleNewRentalChange} className="ml-2 p-3 border border-gray-300 rounded-lg" />
                               </label>
                               <label className="flex items-center text-gray-700">
                                   租赁结束日期:
                                   <input type="date" name="rentalEndDate" value={newRental.rentalEndDate} onChange={handleNewRentalChange} className="ml-2 p-3 border border-gray-300 rounded-lg" />
                               </label>
                               {/* 模拟照片上传 */}
                               <div className="col-span-1 md:col-span-2">
                                   <label htmlFor="photos" className="block text-sm font-medium text-gray-700 mb-2">车辆照片 (模拟)</label>
                                   <input type="file" id="photos" multiple onChange={() => alert('模拟照片上传功能')} className="block w-full text-sm text-gray-500 file:mr-4 file:py-2 file:px-4 file:rounded-lg file:border-0 file:text-sm file:font-semibold file:bg-blue-50 file:text-blue-700 hover:file:bg-blue-100" />
                               </div>
                           </div>
                           <button onClick={startRental} className="mt-6 w-full bg-blue-600 text-white py-3 rounded-lg hover:bg-blue-700 transition duration-300 shadow-md">开始租赁</button>
                       </div>

                       {/* 租赁列表 */}
                       <h3 className="text-2xl font-semibold mb-4 text-gray-800">所有租赁记录</h3>
                       <div className="overflow-x-auto rounded-lg shadow-sm border border-gray-200">
                           <table className="min-w-full divide-y divide-gray-200">
                               <thead className="bg-gray-50">
                                   <tr>
                                       <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">租赁ID</th>
                                       <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">租用人</th>
                                       <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">车辆ID</th>
                                       <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">开始日期</th>
                                       <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">结束日期</th>
                                       <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">状态</th>
                                       <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">操作</th>
                                   </tr>
                               </thead>
                               <tbody className="bg-white divide-y divide-gray-200">
                                   {rentals.map(rental => (
                                       <tr key={rental.id}>
                                           <td className="px-6 py-4 whitespace-nowrap text-sm font-medium text-gray-900">{rental.id}</td>
                                           <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-700">{rental.renterName}</td>
                                           <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-700">{rental.vehicleId}</td>
                                           <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-700">{rental.rentalStartDate}</td>
                                           <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-700">{rental.rentalEndDate}</td>
                                           <td className="px-6 py-4 whitespace-nowrap text-sm">
                                               <span className={`px-2 inline-flex text-xs leading-5 font-semibold rounded-full ${
                                                   rental.rentalStatus === '租用中' ? 'bg-blue-100 text-blue-800' : 'bg-gray-100 text-gray-800'
                                               }`}>
                                                   {rental.rentalStatus}
                                               </span>
                                           </td>
                                           <td className="px-6 py-4 whitespace-nowrap text-right text-sm font-medium">
                                               {rental.rentalStatus === '租用中' && (
                                                   <>
                                                       <button
                                                           onClick={() => returnRental(rental.id)}
                                                           className="text-red-600 hover:text-red-900 mr-4"
                                                       >
                                                           退租
                                                       </button>
                                                       <button
                                                           onClick={() => {
                                                               const newEndDate = prompt('请输入新的租赁结束日期 (YYYY-MM-DD):', rental.rentalEndDate);
                                                               if (newEndDate) renewRental(rental.id, newEndDate);
                                                           }}
                                                           className="text-green-600 hover:text-green-900 mr-4"
                                                       >
                                                           续租
                                                       </button>
                                                       <button
                                                           onClick={() => {
                                                               const newVehId = prompt('请输入新车辆ID:');
                                                               const reason = prompt('请输入换车原因:');
                                                               if (newVehId && reason) swapVehicle(rental.id, rental.vehicleId, newVehId, reason);
                                                           }}
                                                           className="text-purple-600 hover:text-purple-900"
                                                       >
                                                           中途换车
                                                       </button>
                                                   </>
                                               )}
                                           </td>
                                       </tr>
                                   ))}
                               </tbody>
                           </table>
                       </div>
                   </div>
               )}

               {activeTab === 'renterManagement' && (
                   <div className="bg-white p-6 rounded-xl shadow-lg">
                       <h2 className="text-3xl font-bold mb-6 text-gray-800">租用人信息</h2>
                       <div className="overflow-x-auto rounded-lg shadow-sm border border-gray-200">
                           <table className="min-w-full divide-y divide-gray-200">
                               <thead className="bg-gray-50">
                                   <tr>
                                       <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">租用人ID</th>
                                       <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">姓名</th>
                                       <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">身份证号</th>
                                       <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">手机号</th>
                                       <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">地址</th>
                                   </tr>
                               </thead>
                               <tbody className="bg-white divide-y divide-gray-200">
                                   {renters.map(renter => (
                                       <tr key={renter.id}>
                                           <td className="px-6 py-4 whitespace-nowrap text-sm font-medium text-gray-900">{renter.id}</td>
                                           <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-700">{renter.name}</td>
                                           <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-700">{renter.idNumber}</td>
                                           <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-700">{renter.phoneNumber}</td>
                                           <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-700">{renter.address}</td>
                                       </tr>
                                   ))}
                               </tbody>
                           </table>
                       </div>
                   </div>
               )}
           </main>
       </div>
   );
};

export default App;
