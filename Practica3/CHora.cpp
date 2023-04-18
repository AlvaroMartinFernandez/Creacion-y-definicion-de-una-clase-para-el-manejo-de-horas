#include "CHora.h"
#include"Utils.h"
	void CHora::Iniciar(){
		m_nHoras = 0;
		m_nMinutos = 0;
		m_nSegundos = 0;
		m_pszFormato = "";
	}
	bool CHora::AsignarHora(int nHoras,int nMinutos,int nSegundos,string pszFormato){
		m_nHoras = nHoras;
		m_nMinutos = nMinutos;
		m_nSegundos = nSegundos;
		AsignarFormato(pszFormato);
		bool aux = EsHoraCorrecta();
		return aux;

	}
	void CHora::ObtenerHora(int& nHoras,int& nMinutos,int& nSegundos,string& pszFormato)const {
		nHoras = m_nHoras;
		nMinutos = m_nMinutos;
		nSegundos = m_nSegundos;
		pszFormato = m_pszFormato;
	}
	void CHora::Destruir()
	{
		cout << "procedemos a detruir"<< endl;
		m_pszFormato = "";

	}
	bool CHora::EsHoraCorrecta() const{
		if ((m_pszFormato == "24 HORAS") && (m_nHoras <= 23) && (m_nHoras >= 0) && (m_nMinutos <= 59) && (m_nMinutos >= 0) && (m_nSegundos <= 59) && (m_nSegundos >= 0))
			return true;
		else if (((m_pszFormato == "AM") || (m_pszFormato == "PM")) && (m_nHoras <= 12) && (m_nHoras >= 1) && (m_nMinutos <= 59) && (m_nMinutos >= 0) && (m_nSegundos <= 59) && (m_nSegundos >= 0))
			return true;
		else
			return false;
	
	}
	bool CHora::Formato24() const {							
		if (m_pszFormato == "24 HORAS") {
		return true;
		}
		else
			return false;
	}	 							//Realizado
	bool CHora::AsignarFormato(string pszFormato) {
		if (pszFormato.empty() == false) 
		{		
			m_pszFormato = ConverMayus(pszFormato);
			return true;
		}
		return false;
	}
	void VisualizarHora(const CHora& hora) {
		int nHoras = 0, nMinutos = 0, nSegundos = 0;
		string pszFormato = "";
		hora.ObtenerHora(nHoras, nMinutos, nSegundos, pszFormato);
		cout << "La hora sera la siguiente : " << nHoras << ":" << nMinutos << ":" << nSegundos << "  Formato: " << pszFormato << endl;
	}