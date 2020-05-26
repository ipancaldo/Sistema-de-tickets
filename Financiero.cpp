#include "Financiero.h"
#include "Ayuda.h"

using namespace std;

//Utilizados para poder guardar en binario
struct Cli2{
	char nom[30];
	char ape[30];
	char ali[30];
	char mail[30];
	char dir[30];
	char tel[30];
	char dni[30];
	bool estado;
};

struct Prod2{
	char nom_prod[30];
	char marca_prod[30];
	char id_prod[30];
	float valor_prod;
	char descr_prod[100];
};

struct Tickt2{
	char dia[3];
	char mes[3];
	char anio[5];
	char id[500];
	char dni[9];
	char cod_prod[500];
	int cantidad;
	float precio;
	float total;
};
///Este struct se utiliza para imprimir el ticket
struct Compras{
	///Código del producto
	std::string cod;
	///Cantidad items
	int items;
	///Total de la compra
	float total;
	
};
///Lo que va dentro del vector dentro de struct Cl_Pr_Tk
struct ticket_muestra{
	std::string p_nombre;
	std::string p_marca;
	std::string p_descr;
	int items;
	float total;
};
///Struct para devolver todas las cosas del ticket
struct Cl_Pr_Tk{
	std::string id;
	std::string cliente;
	std::string cliente_dni;
	std::string cliente_alias;
	float total_final; ///Monto final de la suma de todos los productos
	vector<ticket_muestra> v;
};



//Se inicializa cargando los datos almacenados en la PC
Financiero::Financiero() {
//	Llamamos las funciones que permiten leer los datos almacenados 
//sobre los clientes y productos
	CargarClientes("Clientes.bin");
	CargarProductos("Productos.bin");
	CargarTickets("Tickets.bin");
}

//Utilizado para poder manipular un cliente
Cliente &Financiero::SeleccionarCliente(int i){
	return m_clientes[i];
}
Producto &Financiero::SeleccionarProducto(int i){
	return m_productos[i];
}
Ticket &Financiero::SeleccionarTicket(int i){
	return m_tickets[i];
}

//Carga todos los clientes almacenados en la PC a la memoria
void Financiero::CargarClientes(std::string clientes){
	ifstream lector1(clientes, ios::binary | ios::ate);
	int size = lector1.tellg()/sizeof(Cli2);	
	lector1.seekg(0);
	//generamos un struct donde guardaremos la los datos para posteriormente ingresarlos en un vector
	Cli2 muestra_bin;

	//Vector auxiliar para poder ir almacenando los datos de los clientes (struct anterior)
	vector<Cliente> v1;

	for(int i=0;i<size;++i) { 
		lector1.read(reinterpret_cast<char*>(&muestra_bin),sizeof(Cli2));
		//Vamos generando los clientes e ingresandolos en el vector auxiliar
		Cliente carga(muestra_bin.nom, muestra_bin.ape, muestra_bin.dni, 
					  muestra_bin.ali, muestra_bin.dir, muestra_bin.tel, 
					  muestra_bin.mail, muestra_bin.estado);		
		v1.push_back(carga);
		//Pasamos los datos del vector auxiliar al vector miembro
		this->m_clientes = v1;
	}
	lector1.close();
}

void Financiero::CargarProductos(std::string productos){
	ifstream lector2(productos, ios::binary | ios::ate);
	int size = lector2.tellg()/sizeof(Prod2);	
	lector2.seekg(0);
	Prod2 muestra_prod_bin;
	
	//Vector auxiliar para poder ir almacenando los datos de los productos
	vector<Producto> v2;
	
	for(int i=0;i<size;++i) { 
		lector2.read(reinterpret_cast<char*>(&muestra_prod_bin),sizeof(Prod2));
		//Vamos generando los productos e ingresandolos en el vector auxiliar
		Producto carga_prod(muestra_prod_bin.nom_prod, muestra_prod_bin.marca_prod, 
							muestra_prod_bin.id_prod, muestra_prod_bin.valor_prod, 
							muestra_prod_bin.descr_prod);		
		v2.push_back(carga_prod);
		//Pasamos los datos del vector auxiliar al vector miembro
		this->m_productos = v2;
	}
	lector2.close();
	
};

void Financiero::CargarTickets(std::string tickets){
	ifstream lector3(tickets, ios::binary | ios::ate);
	int size = lector3.tellg()/sizeof(Tickt2);
	lector3.seekg(0);
	Tickt2 muestra_tickt_bin;
	
	//Vector auxiliar para poder ir almacenando los datos de los productos
	vector<Ticket> v3;
	
	for(int i=0;i<size;++i) { 
		lector3.read(reinterpret_cast<char*>(&muestra_tickt_bin),sizeof(Tickt2));
		//Vamos generando los tickets e ingresandolos en el vector auxiliar
		Ticket carga_tickt(muestra_tickt_bin.dia, muestra_tickt_bin.mes, muestra_tickt_bin.anio, 
						   muestra_tickt_bin.id, muestra_tickt_bin.dni, muestra_tickt_bin.cod_prod,
						   muestra_tickt_bin.precio, muestra_tickt_bin.cantidad);
		v3.push_back(carga_tickt);
		//Pasamos los datos del vector auxiliar al vector miembro
		this->m_tickets = v3;
	}
	lector3.close();
	
};

//Verifica la cantidad total de clientes
int Financiero::CantidadClientes() const{
	return m_clientes.size();
}
//Verifica la cantidad de productos
int Financiero::CantidadProductos() const{
	return m_productos.size();
}
//Agrega un cliente nuevo a los existentes
void Financiero::AgregarCliente(Cliente NuevoCliente){
	m_clientes.push_back(NuevoCliente);
	GuardarClientes();
}
//Elimina un cliente seleccionado. SÓLO PARA CASOS ESPECIALES
void Financiero::EliminarCliente(int i){
	m_clientes.erase(m_clientes.begin()+i); //Ponemos -1 porque pedimos en el programa valores entre 1 y v.size()
	GuardarClientes();
}
//Agrega un producto nuevo a los existentes
void Financiero::AgregarProducto(Producto NuevoProducto){
	m_productos.push_back(NuevoProducto);
	GuardarProductos();
}
//Elimina un producto seleccionado
void Financiero::EliminarProducto(int i){
	m_productos.erase(m_productos.begin()+i-1, m_productos.begin()+i); //Ponemos -1 porque pedimos en el programa valores entre 1 y v.size()
	GuardarProductos();
}
//Agrega un ticket nuevo a los existentes
void Financiero::AgregarTicket(Ticket NuevoTicket){
	m_tickets.push_back(NuevoTicket);
	GuardarTicketsBin();
}
//Elimina un ticket seleccionado
void Financiero::EliminarTicket(int i){
	m_tickets.erase(m_tickets.begin()+i-1, m_tickets.begin()+i); //Ponemos -1 porque pedimos en el programa valores entre 1 y v.size()
	GuardarTicketsBin();
}
//Verificar cantidad de tickets
int Financiero::CantidadTickets() const{
	return m_tickets.size();
}

std::vector<int> Financiero::MostrarClientesHabilitados(bool m){
	std::vector<int> v;
	if(m == true){
		for(int i=0;i<CantidadClientes();i++) { 
			if(m_clientes[i].VerEstado() == true){
				v.push_back(i);
			}
		}
	}else{
		for(int i=0;i<CantidadClientes();i++) { 
			if(m_clientes[i].VerEstado() == false){
				v.push_back(i);
			}
		}
	}
	return v;
}

//Lista todos los códigos en USO
std::vector<std::string> Financiero::ListarCodProd(){
	string primer_cod = "-1";
	std::vector<std::string> cods;
	for(int i=0;i<CantidadProductos();i++) { 
		Producto a = SeleccionarProducto(i);
		if(primer_cod != a.prod_VerCodigo()){
			cods.push_back(a.prod_VerCodigo());
			primer_cod = a.prod_VerCodigo();
		}
	}
	return cods;
}

void Financiero::GuardarClientes(){	
	ofstream escribir("Clientes.bin", ios::binary | ios::trunc);
	for(size_t i=0;i<m_clientes.size();i++) {
		Cli2 aux;
		strcpy(aux.nom,m_clientes[i].VerNombre().c_str());
		strcpy(aux.ape,m_clientes[i].VerApellido().c_str());
		strcpy(aux.dni,m_clientes[i].VerDNI().c_str());
		strcpy(aux.ali,m_clientes[i].VerAlias().c_str());
		strcpy(aux.dir,m_clientes[i].VerDireccion().c_str());
		strcpy(aux.tel,m_clientes[i].VerTelefono().c_str());	
		strcpy(aux.mail,m_clientes[i].VerMail().c_str());			
		aux.estado = m_clientes[i].VerEstado();
		
		escribir.write(reinterpret_cast<char*>(&aux),sizeof(aux));
	}
	escribir.close();
}

void Financiero::GuardarProductos(){	
	ofstream escribir("Productos.bin", ios::binary | ios::trunc);
	for(size_t i=0;i<m_productos.size();i++) {
		Prod2 aux;
		strcpy(aux.nom_prod, m_productos[i].prod_VerNombre().c_str());
		strcpy(aux.marca_prod, m_productos[i].prod_VerMarca().c_str());
		strcpy(aux.id_prod, m_productos[i].prod_VerCodigo().c_str());
		aux.valor_prod = m_productos[i].prod_VerValor();
		strcpy(aux.descr_prod, m_productos[i].prod_VerDescr().c_str());
		
		escribir.write(reinterpret_cast<char*>(&aux),sizeof(aux));
	}
	escribir.close();
}

void Financiero::GuardarTicketsBin(){	
	ofstream escribir("Tickets.bin", ios::binary | ios::trunc);
	for(size_t i=0;i<m_tickets.size();i++) {
		Tickt2 aux;
		strcpy(aux.dia, m_tickets[i].ticket_VerDia().c_str());
		strcpy(aux.mes, m_tickets[i].ticket_VerMes().c_str());
		strcpy(aux.anio, m_tickets[i].ticket_VerAnio().c_str());
		strcpy(aux.id, m_tickets[i].ticket_VerId().c_str());
		strcpy(aux.dni, m_tickets[i].ticket_VerDNI().c_str());
		strcpy(aux.cod_prod, m_tickets[i].ticket_VerCodigoProd().c_str());
		aux.cantidad = m_tickets[i].ticket_VerCantidadItems();
		aux.precio = m_tickets[i].ticket_VerPrecio();
		aux.total = m_tickets[i].ticket_VerTotal();
		
		escribir.write(reinterpret_cast<char*>(&aux),sizeof(aux));
	}
	escribir.close();
}

//Busca por algún criterio y devuelve la posición.
int Financiero::BuscarNombre(std::string Nombre) {
	pasar_a_minusculas(Nombre);
	int cantidad = CantidadClientes();
	for (int i=0;i<cantidad;i++) {
		Cliente &c = m_clientes[i];
		std::string nombre_actual = c.VerNombre();
		pasar_a_minusculas(nombre_actual);
		if (nombre_actual.find(Nombre,0)!=std::string::npos)
			return i;
	}
	return no_encontrado;
}

int Financiero::BuscarApellido(std::string Apellido){
	pasar_a_minusculas(Apellido);
	int cantidad = CantidadClientes();
	for (int i=0;i<cantidad;i++) {
		Cliente &c = m_clientes[i];
		std::string apellido_actual = c.VerApellido();
		pasar_a_minusculas(apellido_actual);
		if (apellido_actual.find(Apellido,0)!=std::string::npos)
			return i;
	}
	return no_encontrado;
}

int Financiero::BuscarAlias(std::string Alias){
	pasar_a_minusculas(Alias);
	int cantidad = CantidadClientes();
	for (int i=0;i<cantidad;i++) {
		Cliente &c = m_clientes[i];
		std::string alias_actual = c.VerAlias();
		pasar_a_minusculas(alias_actual);
		if (alias_actual.find(Alias,0)!=std::string::npos)
			return i;
	}
	return no_encontrado;
}

int Financiero::BuscarMail(std::string Mail){
	pasar_a_minusculas(Mail);
	int cantidad = CantidadClientes();
	for (int i=0;i<cantidad;i++) {
		Cliente &c = m_clientes[i];
		std::string mail_actual = c.VerMail();
		pasar_a_minusculas(mail_actual);
		if (mail_actual.find(Mail,0)!=std::string::npos)
			return i;
	}
	return no_encontrado;
}

int Financiero::BuscarTelefono(std::string Telefono){
	pasar_a_minusculas(Telefono);
	int cantidad = CantidadClientes();
	for (int i=0;i<cantidad;i++) {
		Cliente &c = m_clientes[i];
		std::string telefono_actual = c.VerTelefono();
		pasar_a_minusculas(telefono_actual);
		if (telefono_actual.find(Telefono,0)!=std::string::npos)
			return i;
	}
	return no_encontrado;
}

int Financiero::BuscarDireccion(std::string Direccion){
	pasar_a_minusculas(Direccion);
	int cantidad = CantidadClientes();
	for (int i=0;i<cantidad;i++) {
		Cliente &c = m_clientes[i];
		std::string direccion_actual = c.VerDireccion();
		pasar_a_minusculas(direccion_actual);
		if (direccion_actual.find(Direccion,0)!=std::string::npos)
			return i;
	}
	return no_encontrado;
}

int Financiero::BuscarCodProd(std::string codigo){
	int pos;
	for(size_t i=0;i<m_productos.size();i++) { 
		if(codigo == m_productos[i].prod_VerCodigo()){
			pos = i;
			i = m_productos.size();
		}
	}
	return pos;
}

int Financiero::BuscarDni(std::string Dni) {
	for (int i=0;i<CantidadClientes();i++) {
		Cliente &c = m_clientes[i];
		std::string dni_actual = c.VerDNI();
		if (dni_actual.find(Dni,0)!=std::string::npos)
			return i;
	}
	return no_encontrado;
}

int Financiero::BuscarIdTicket(std::string id) {
	for (int i=0;i<CantidadTickets();i++) {
		Ticket &t = m_tickets[i];
		if (t.ticket_VerId().find(id,0)!=std::string::npos)
			return i;
	}
	return no_encontrado;
}




std::string Financiero::ticket_VerUltimoIdString(){
	ifstream texto("TicketsID.txt", ios::app);
	std::string id_vacio, id_archivo;
	while(texto >> id_archivo){
		id_vacio = id_archivo;
	}
	texto.close();
	return id_vacio;
}

int Financiero::ticket_VerUltimoIdInt(){
	ifstream texto("TicketsID.txt", ios::app);
	int id_vacio, id_archivo;
	while(texto >> id_archivo){
		id_vacio = id_archivo;
	}
	texto.close();
	return id_vacio;
}

//Muestra el monto total vendido por un ticket
float Financiero::TotalTicket(std::string id){
	float suma = 0;
	for(int i=0;i<CantidadTickets();i++) { 
		if(m_tickets[i].ticket_VerId() == id)
			suma += m_tickets[i].ticket_VerTotal();
	}
	return suma;	
}

std::string Financiero::prod_GenerarCodBarras(){
	ifstream texto("ProductosCB.txt", ios::app);
	int id_vacio, id_archivo;
	while(texto >> id_archivo){
		id_vacio = id_archivo;
	}
	texto.close();
	
	///Generamos el ID como número para sumarle 1, pero luego lo transformamos a string para facilitar el uso
	ofstream reescribiendo_texto("ProductosCB.txt", ios::app);
	reescribiendo_texto << endl << id_vacio+1;
	reescribiendo_texto.close();
	
	
	///Acá abrimos nuevamente el archivo pero esta vez lo interpretamos como string
	ifstream texto_string("ProductosCB.txt", ios::app);
	std::string id_string_ret, id_string_archivo;
	while(texto_string >> id_string_archivo){
		///Acá ya leemos el número +1 guardado anteriormente y convertido a string
		id_string_ret = id_string_archivo;
	}
	texto_string.close();
	
	return id_string_ret;
}

std::string Financiero::ticket_GenerarId(){
	ifstream texto("TicketsID.txt", ios::app);
	int id_vacio, id_archivo;
	while(texto >> id_archivo){
		id_vacio = id_archivo;
	}
	texto.close();
	
	///Generamos el ID como número para sumarle 1, pero luego lo transformamos a string para facilitar el uso
	ofstream reescribiendo_texto("TicketsID.txt", ios::app);
	reescribiendo_texto << endl << id_vacio+1;
	reescribiendo_texto.close();

	
	///Acá abrimos nuevamente el archivo pero esta vez lo interpretamos como string
	ifstream texto_string("TicketsID.txt", ios::app);
	std::string id_string_ret, id_string_archivo;
	while(texto_string >> id_string_archivo){
		///Acá ya leemos el número +1 guardado anteriormente y convertido a string
		id_string_ret = id_string_archivo;
	}
	texto_string.close();
	
	return id_string_ret;
}

	

void Financiero::ImprimirTicket(std::string codigo){
	///Primero, debemos ordenar los tickets para poder buscar por código
	Ordenar(por_id);
	///Segundo, buscar todos los ID's iguales, guardando el DNI Cliente y código/s del/os producto/s
	std::string buscar_comprador;
	vector<Compras> productos_comprados;
	for(int i=0;i<CantidadTickets();i++) { 
		if(codigo == m_tickets[i].ticket_VerId()){
			Compras aux;
			///Buscamos el DNI del comprador para luego buscarlo por afuera de este for.
			///Para no hacer demasiadas iteraciones
			buscar_comprador = m_tickets[i].ticket_VerDNI();
			///Estos dos datos sólo lo tiene el ticket, porque tiene una cantidad x comprada y un valor histórico
			aux.cod = m_tickets[i].ticket_VerCodigoProd();
			aux.items = m_tickets[i].ticket_VerCantidadItems();
			aux.total = m_tickets[i].ticket_VerTotal();
			
			
			///Lo mismo para el producto comprado
			productos_comprados.push_back(aux);
		}
	}
	///Hacemos realizamos la busqueda del cliente
	Cliente comprador;
	for(int i=0;i<CantidadClientes();i++) { 
		if(buscar_comprador == m_clientes[i].VerDNI()){
			comprador = m_clientes[i];
			///Para dejar de iterar, ya que no es necesario seguir buscando porque el DNI es único
			i = CantidadClientes();
		}
	}
	///Hacemos la busqueda del producto
	vector<Producto> productos;
	for(size_t i=0;i<productos_comprados.size();i++) { 
		for(int j=0;j<CantidadProductos();j++) { 
			if(productos_comprados[i].cod == m_productos[j].prod_VerCodigo()){
				productos.push_back(m_productos[i]);
			}
		}
	}
	///Nombre del archivo a crear
	stringstream ss;
	ss << "ticket_" << codigo << ".txt";
	///Creamos el TXT del ticket
	ofstream creando_ticket(ss.str(), ios::trunc);
	creando_ticket << "Ticket número: " << codigo << endl;
	creando_ticket << "Datos del comprador:" << endl
					<< "Nombre y apellido: " << comprador.VerNombre() << " " << comprador.VerApellido() << endl
					<< "DNI: " << comprador.VerDNI() << endl
					<< "Local: " << comprador.VerAlias() << endl;
	creando_ticket << "************************" << endl;
	creando_ticket << "   Producto                   Cantidad          Precio" << endl;
	for(size_t i=0;i<productos_comprados.size();i++) { 
		creando_ticket << "- " << productos[i].prod_VerNombre() << " - " << productos[i].prod_VerMarca()
						<< "   " << productos_comprados[i].items << "    $" << productos_comprados[i].total << endl
						<< productos[i].prod_VerDescr() << endl;
	}
	creando_ticket << "Total: $" << TotalTicket(codigo);
	
	creando_ticket.close();
}


std::vector<std::string> Financiero::IdTicketsNoRepetidos(){
	string primer_id = "-1";
	std::vector<std::string> no_repetidos;
	for(int i=0;i<CantidadTickets();i++) { 
		Ticket a = SeleccionarTicket(i);
		if(primer_id != a.ticket_VerId()){
			no_repetidos.push_back(a.ticket_VerId());
			primer_id = a.ticket_VerId();
		}
	}
	return no_repetidos;
}


struct Cl_Pr_Tk Financiero::MostrarTicket(std::string id){
	///Primero, debemos ordenar los tickets para poder buscar por código
	Ordenar(por_id);
	///Segundo, buscar todos los ID's iguales, guardando el DNI Cliente y código/s del/os producto/s
	std::string buscar_comprador;
	vector<Compras> productos_comprados;
	for(int i=0;i<CantidadTickets();i++) { 
		if(id == m_tickets[i].ticket_VerId()){
			Compras aux;
			///Buscamos el DNI del comprador para luego buscarlo por afuera de este for.
			///Para no hacer demasiadas iteraciones
			buscar_comprador = m_tickets[i].ticket_VerDNI();
			///Estos dos datos sólo lo tiene el ticket, porque tiene una cantidad x comprada y un valor histórico
			aux.cod = m_tickets[i].ticket_VerCodigoProd();
			aux.items = m_tickets[i].ticket_VerCantidadItems();
			aux.total = m_tickets[i].ticket_VerTotal();
			
			
			///Lo mismo para el producto comprado
			productos_comprados.push_back(aux);
		}
	}
	///Hacemos realizamos la busqueda del cliente
	Cliente comprador;
	for(int i=0;i<CantidadClientes();i++) { 
		if(buscar_comprador == m_clientes[i].VerDNI()){
			comprador = m_clientes[i];
			///Para dejar de iterar, ya que no es necesario seguir buscando porque el DNI es único
			i = CantidadClientes();
		}
	}

	///Hacemos la busqueda del producto
	vector<Producto> productos;
	for(size_t i=0;i<productos_comprados.size();i++) { 
		for(int j=0;j<CantidadProductos();j++) { 
			if(productos_comprados[i].cod == m_productos[j].prod_VerCodigo()){
				productos.push_back(m_productos[i]);
			}
		}
	}
	Cl_Pr_Tk cpr;
	///Lo que devolveremos
	cpr.id = id; ///Id del ticket
	cpr.cliente = comprador.VerNombre()+", "+comprador.VerApellido(); ///Nombre y apellido clinete
	cpr.cliente_dni = comprador.VerDNI(); ///DNI del cliente
	cpr.cliente_alias =  comprador.VerAlias(); ///Alias del cliente
	vector<ticket_muestra> v; ///Para productos y valores referenciales a tickets
	cpr.total_final = TotalTicket(id);
	for(size_t i=0;i<productos_comprados.size();i++) {
		ticket_muestra tm;
		tm.p_nombre = productos[i].prod_VerNombre();///Nombre del producto
		tm.p_marca = productos[i].prod_VerMarca();///Marca del producto
		tm.p_descr = productos[i].prod_VerDescr();///Descripción del producto
		tm.items = productos_comprados[i].items;///Cantidad de items de la compra
		tm.total = productos_comprados[i].total;///Total en la compra
		v.push_back(tm);
	}
	
	cpr.v = v;
	
	return cpr;
}











void Financiero::Ordenar(CriterioOrden Criterio){
	switch(Criterio){
	///Orden para clientes
	case por_nombre:
		sort(m_clientes.begin(),m_clientes.end(),criterio_de_comparacion_nombre);
		break;
	case por_apellido:
		sort(m_clientes.begin(),m_clientes.end(),criterio_de_comparacion_apellido); 
		break;
	case por_alias:
		sort(m_clientes.begin(),m_clientes.end(),criterio_de_comparacion_alias); 
		break;
	case por_mail:
		sort(m_clientes.begin(),m_clientes.end(),criterio_de_comparacion_mail); 
		break;
	case por_direccion:
		sort(m_clientes.begin(),m_clientes.end(),criterio_de_comparacion_direccion); 
		break;
	case por_telefono:
		sort(m_clientes.begin(),m_clientes.end(),criterio_de_comparacion_telefono); 
		break;
	case por_dni:
		sort(m_clientes.begin(),m_clientes.end(),criterio_de_comparacion_dni); 
		break;
	
	///Orden para tickets
	case por_id:
		sort(m_tickets.begin(),m_tickets.end(),criterio_de_comparacion_id);
		break;
	case por_fecha:
		sort(m_tickets.begin(),m_tickets.end(),criterio_de_comparacion_fecha);
		break;
	case por_dni_t:
		sort(m_tickets.begin(),m_tickets.end(),criterio_de_comparacion_dni_t);
		break;
	case por_cod_prod:
		sort(m_tickets.begin(),m_tickets.end(),criterio_de_comparacion_cod_prod);
		break;
	
	///Orden para productos
	case por_pnombre:
		sort(m_productos.begin(),m_productos.end(),criterio_de_comparacion_pnombre);
		break;
	case por_pmarca:
		sort(m_productos.begin(),m_productos.end(),criterio_de_comparacion_pmarca);
		break;
	case por_pcodigo:
		sort(m_productos.begin(),m_productos.end(),criterio_de_comparacion_pcodigo);
		break;
	case por_pvalor:
		sort(m_productos.begin(),m_productos.end(),criterio_de_comparacion_pvalor);
		break;
	case por_pdescripcion:
		sort(m_productos.begin(),m_productos.end(),criterio_de_comparacion_pdescripcion);
		break;
	}
}
